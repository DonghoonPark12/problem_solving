   /*  includes
    ****************************************************************/
#include <string.h>
#include "IFX_Framework.h"
#include "IFX_DbC.h"

//#if defined (IFX_CFG_IOCTL) || defined(DOXYGEN)

#include "../IFX_Tasks/IFX_Tasks.h"
#include "../IFX_Kernel/IFX_Mutex.h"
#include "../IFX_Memory/IFX_Memory.h"
#include "../IFX_Ioctl/IFX_Ioctl_Defs.h"
#include "../IFX_Ioctl/IFX_Ioctl_Interface.h"
#include "../IFX_Ioctl/IFX_Ioctl_Intern.h"
#include "IFX_Io_Manager.h"
#include "IFX_Config.h"
#include "../IFX_Interrupts/IFX_Interrupts.h"

#include "../IFX_Nvm/IFX_Nvm.h"
#ifdef SLE70
#include <srom.h>
#endif


    /*  pragmas
     ****************************************************************/

     /*  defines
      ****************************************************************/
      /* Make filename available to DbC */
DEFINE_THIS_FILE
/** @defgroup init_stages Index to the function pointer array in the drivers function structure.*/
//@{
#define IFX_IO_MANAGER_FUNC_OPEN            0
#define IFX_IO_MANAGER_FUNC_CLOSE           1
#define IFX_IO_MANAGER_FUNC_IOCTL           2
#define IFX_IO_MANAGER_FUNC_CANCEL_IO       3
#define IFX_IO_MANAGER_FUNC_INIT            4
//}@

/** Defines for accessing the device list area */
#if defined (SLE70)
SROM_MC(HCONST_IFX_DEVICE_LIST)
#define pIFX_Iom_DeviceCfg    (DEVICE_INFO*)SROM_MC_TRG(HCONST_IFX_DEVICE_LIST)
#define pIFX_Iom_DeviceCfgEnd (DEVICE_INFO*)SROM_MC_END(HCONST_IFX_DEVICE_LIST)
#elif defined (SLE90)
#if defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic push
// Suppress dollar-in-identifier-extension warning, because we are accessing linker symbols directly.
// This is required by design (macro IFX_DEVICE_LIST_ENTRY can be used across different files).
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"
#endif

extern DEVICE_INFO Load$$ER_AN_USER_RO_DEVICE_LIST$$RO$$Base;
extern DEVICE_INFO Load$$ER_AN_USER_RO_DEVICE_LIST$$RO$$Limit;
#define pIFX_Iom_DeviceCfg    &Load$$ER_AN_USER_RO_DEVICE_LIST$$RO$$Base
#define pIFX_Iom_DeviceCfgEnd &Load$$ER_AN_USER_RO_DEVICE_LIST$$RO$$Limit

#if defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic pop
#endif
#else
#error "Platform not supported!"
#endif


/*  private prototypes
 ****************************************************************/

    __STATIC STATUS deviceInit(uint8_t stage);
__STATIC STATUS getDeviceInfo(DEVICE_TYPE Device, PDEVICE_INFO* p);
__STATIC HANDLE getHandleFromContext(PCONTEXT_INFO Context);

#ifdef DEBUG
__STATIC uint8_t IFX_Iom_IsHandleValid(HANDLE Handle, PCONTEXT_INFO_ARRAY p);
#endif

/*  constants
 ****************************************************************/

 /*  variables
  ****************************************************************/
__STATIC uint8_t IFX_Iom_InitStage;

/** @brief static memory space providing @sa HANDLE to application code
 **
 ** This table keeps the core information of the IO Manager.
 ** The default allocation is a table which provides a limited space (@sa DIMCONTEXTINFO)
 ** for handles. Extensions of this table are dynamic and are refences by the Next pointer
 **/
__ALIGN(4) __STATIC CONTEXT_INFO_ARRAY IFX_IomContextInfoArray[1];

/*  functions
 ****************************************************************/

 /**
  ** @brief
  ** set IO Manger initialization state variable IFX_Iom_InitState to IFX_IOM_NOT_INITIALIZED.
  **
  ** @retval STATUS_SUCCESS
  **/
STATUS IFX_Iom_Init(void) SECT90(ifx_startup_code);
STATUS IFX_Iom_Init(void)
{
    // clear context info array for later open calls
    IFX_MemSetZero(&IFX_IomContextInfoArray, sizeof(IFX_IomContextInfoArray));
    // start initialization with first stage
    IFX_Iom_InitStage = IFX_IOM_INI_STAGE_1;
    return STATUS_SUCCESS;
}

/**
 ** @brief
 ** IFX_Device_Init - initializes the IOCTL interface of the drivers.
 **
 ** @retval STATUS_SUCCESS                  The IOCTL interface was configured successfully.
 ** @retval STATUS_DEVICE_INIT_INCOMPLETE   One or more drivers are still to be initialized.
 **                                         IFX_Device_Init() must be called again.
 **/
STATUS IFX_Iom_Device_Init(void)
{
    STATUS retStatus;

    // check if there is one more stage to initialize
    if (IFX_Iom_InitStage <= IFX_IOM_INI_STAGE_MAX)
    {
        retStatus = deviceInit(IFX_Iom_InitStage);

        if (retStatus == STATUS_SUCCESS)
        {
            // stage was initialized successfully => increase stage
            IFX_Iom_InitStage++;

            // this is a optimization to save one more IFX_Device_Init() call
            if (IFX_Iom_InitStage <= IFX_IOM_INI_STAGE_MAX) // IFX_Iom_InitStage <= 2
            {
                retStatus = STATUS_DEVICE_INIT_INCOMPLETE;
            }
        }
    }
    else
    {
        // nothing legt to do, so just return success
        retStatus = STATUS_SUCCESS;
    }

    return retStatus;
}


/**
 ** @brief
 ** IFX_Device_Open - opens a device and returns the handle to the device.
 **
 ** @param[in]  device - The name of the desired device
 ** @param[in]  mode - Share mode
 **
 ** @retval HANDLE
 **         The HANDLE to the device.
 **      INVALID_HANDLE in the case of an error.
 **/
HANDLE IFX_Device_Open(DEVICE_TYPE device, uint32_t mode) // The name of the desired device, share mode
{
    PDEVICE_INFO devInfo = NULL;    // Pointer, basic information for the IO Manager.
    CONTEXT_INFO contextInfo;       // context information for the IO Manager.
    STATUS status = STATUS_ACCESS_DENIED;
    HANDLE handle = INVALID_HANDLE;

    /* opening a driver is only allowed, if all the driver have been
      fully initialized by the IO Manger  */
    if (IFX_Iom_InitStage > IFX_IOM_INI_STAGE_MAX)
    {
        status = getDeviceInfo(device, &devInfo); //If selectec DEVICE_TYPE is in the 'ER_AN_USER_RO_DEVICE_LIST'
                                                  //devInfo pointer to device info of driver
        if (IS_STATUS_SUCCESS(status))
        {
            contextInfo.DriverContext.pDriverInfo = &devInfo->DriverInfo; //&(*devInfo).DriverInfo
            contextInfo.DriverContext.pContextInformation = NULL;

            status = ((PDRIVER_OPEN)devInfo->DriverInfo.pInterface->functions[IFX_IO_MANAGER_FUNC_OPEN])(&contextInfo.DriverContext, mode); // mode parameter passed through Erd
        }

        if (!IS_STATUS_SUCCESS(status))
        {
            return INVALID_HANDLE;
        }

        handle = getHandleFromContext(&contextInfo);
    }

    return handle;
}

/**
 ** @brief
 ** IFX_Device_Close - closes an instance of a device driver.
 **
 ** @param[in]  Handle - The handle to a opened device
 **
 ** @retval STATUS_SUCCESS
 **         The device was closed successfully.
 **/
STATUS IFX_Device_Close(HANDLE Handle)
{
    STATUS status = STATUS_ACCESS_DENIED;
    PCONTEXT_INFO contextInfo = (PCONTEXT_INFO)Handle;

    PDRIVER_CLOSE driverClose;
    DRIVER_CONTEXT* driverContext = &contextInfo->DriverContext;

    status = STATUS_INVALID_HANDLE;
#ifdef DEBUG
    ENSURE(IFX_Iom_IsHandleValid(Handle, &IFX_IomContextInfoArray[0]));
#endif

    if (Handle != INVALID_HANDLE)
    {
        driverClose = (PDRIVER_CLOSE)contextInfo->DriverContext.pDriverInfo->pInterface->functions[IFX_IO_MANAGER_FUNC_CLOSE];
        status = driverClose(driverContext);
    }

    if (IS_STATUS_SUCCESS(status))
    {
        IFX_Mutex_Lock(IFX_MUTEX_IOM_CONTEXT_INFO_ARRAY);
        /** @note this operation must be executed atomically, because access
            to this object may interfere with @sa IFX_Device_Open() and
            @sa IoForceCloseHandlesFromTaskId().
         **/
        contextInfo->DriverContext.pDriverInfo = NULL;               // clear handle
        /// => asynchronous events could spoil consistency of this object at this point -> protection needed
        contextInfo->TaskId = IFX_INVALID_TASK;   // handle is freed now, remove reference to TaskId
        IFX_Mutex_Unlock(IFX_MUTEX_IOM_CONTEXT_INFO_ARRAY);
    }

    return status;
}

/**
 ** @brief
 ** Retrieves the driver information from handle and passes parameters to the driver
 **
 ** @param[in]   Handle - The handle to a opened device
 ** @param[in]   ControlCode - Controlcode of the requested operation
 ** @param[in]   InParameter - Structure with input parameter or NULL
 ** @param[in]  OutParameter - Structure with output parameter or NULL
 **
 ** @retval STATUS_SUCCESS
 **         The operation was processed successfully.
 **/
STATUS IFX_Device_IoCtl(HANDLE Handle,             // handle to a device
    uint32_t ControlCode,        // control code of operation to perform
    IN  IOCTL_PARAMETER* InParameter,
    OUT IOCTL_PARAMETER* OutParameter)

{
    STATUS status = STATUS_INVALID_HANDLE;

    if ((Handle != INVALID_HANDLE) && (Handle != NULL))
    {
        PDRIVER_IOCTRL driverIoctl;
        PCONTEXT_INFO contextInfo = (PCONTEXT_INFO)Handle;

        driverIoctl = (PDRIVER_IOCTRL)*contextInfo->DriverContext.pDriverInfo->pInterface->functions[IFX_IO_MANAGER_FUNC_IOCTL];
        status = driverIoctl(&contextInfo->DriverContext, ControlCode, InParameter, OutParameter);

        SCHEDULE_BARRIER_ISSC_WORKAROUND();

        if (!IS_STATUS_SUCCESS(status))
        {
            /* at this point you can establish a central failure handling */
        }
    }

    return status;
}


#if (IFX_CFG_MULTI_IO == 1)
/**
 ** @brief
 ** required for multi IO support. searches the list of open handles related to a given multi io task and frees them
 **
 ** This function is required to support resource clean up actions after a multi IO task shall be shut down
 ** e.g. by a reset or shutdown event. It searches the list of currently open handles related to a given multi io task (TaskId)
 ** and frees the IO Manger specific resources.
 ** @note  This function is called asynchronously by the task management and might interrupt an interface task at any time.
 **
 ** @param[in]  TaskId
 **
 ** @return status of operation
 ** @retval STATUS_SUCCESS  if all handles could be found
 ** @retval STATUS_INVALID_HANDLE in case no open handle was found
 **/
STATUS IoForceCloseHandlesFromTaskId(IFX_TASK_IDS TaskId)
{
    STATUS status = STATUS_INVALID_HANDLE;
    uint32_t i;
    PCONTEXT_INFO_ARRAY pTempContextInfoArray = IFX_IomContextInfoArray;

    /* get exclusive write access to table */
    IFX_Mutex_Lock(IFX_MUTEX_IOM_CONTEXT_INFO_ARRAY);
    // search for handles connected to a specific Task

    do
    {
        for (i = 0; i < DIMCONTEXTINFO; i++)
        {
            if (pTempContextInfoArray->ContextInfo[i].TaskId == TaskId)
            {
                PDRIVER_CANCEL_IO cancelIO;
                /** @note This function is invoked asynchronously, thus bug check for current object if have
                    been spoiled at this point, so taking care here not to access an already invalidated reference */
                REQUIRE(pTempContextInfoArray->ContextInfo[i].DriverContext.pDriverInfo != NULL);
                // calling the every driver close functions may be to expensive, so reduce effort to drivers requiring a cleanup for async reset events
                //  driverClose   = (PDRIVER_CLOSE) pTempContextInfoArray->ContextInfo[i].DriverContext.pDriverInfo->pInterface->functions[IFX_IO_MANAGER_FUNC_CLOSE];
                //  status = driverClose( &pTempContextInfoArray->ContextInfo[i].DriverContext);

                if (pTempContextInfoArray->ContextInfo[i].DriverContext.pDriverInfo->pInterface->count > IFX_IO_MANAGER_FUNC_CANCEL_IO &&
                    pTempContextInfoArray->ContextInfo[i].DriverContext.pDriverInfo->pInterface->functions[IFX_IO_MANAGER_FUNC_CANCEL_IO] != NULL)
                {
                    cancelIO = (PDRIVER_CLOSE)pTempContextInfoArray->ContextInfo[i].DriverContext.pDriverInfo->pInterface->functions[IFX_IO_MANAGER_FUNC_CANCEL_IO];

                    if (cancelIO != NULL)
                    {
                        status = cancelIO(&pTempContextInfoArray->ContextInfo[i].DriverContext);
                    }
                }

                pTempContextInfoArray->ContextInfo[i].DriverContext.pDriverInfo = NULL;             // clear handle
                pTempContextInfoArray->ContextInfo[i].TaskId = IFX_INVALID_TASK; // handle is freed now, remove reference to TaskId
            }
        }

        pTempContextInfoArray = pTempContextInfoArray->Next; // get next Array
    } while (pTempContextInfoArray != NULL);

    IFX_Mutex_Unlock(IFX_MUTEX_IOM_CONTEXT_INFO_ARRAY);

    return status;
}
#endif // (IFX_CFG_MULTI_IO == 1)

/**
 ** @brief Reads the device configuration and initializes the IOCTL interface of the drivers.
 **
 ** param[in] stage - current stage indicating which drivers should be initialized
 **
 ** @retval STATUS_SUCCESS
 **         The IOCTL interface was configured successfully.
 **/
__STATIC STATUS deviceInit(uint8_t stage)
{
    STATUS status = STATUS_SUCCESS;
    STATUS retStatus = STATUS_SUCCESS;
    DEVICE_INFO* pRunner;

    for (pRunner = pIFX_Iom_DeviceCfg; pRunner < pIFX_Iom_DeviceCfgEnd; pRunner++)
    {
        // check for driver for this stage
        if (pRunner->InitStage == stage &&
            pRunner->DriverInfo.pInterface->count > IFX_IO_MANAGER_FUNC_INIT &&
            pRunner->DriverInfo.pInterface->functions[IFX_IO_MANAGER_FUNC_INIT] != NULL)
        {
            // do the driver init if there is an init function for this driver
            status = ((PDRIVER_INIT)pRunner->DriverInfo.pInterface->functions[IFX_IO_MANAGER_FUNC_INIT])(&pRunner->DriverInfo);
            //                                                                         ก่ pDriverInfo(which is struct pointer, PDRIVER_INFO) get address of DriverInfo
            //                                    ก่     : DRV_INTERFACE's member function pointer
            //                        ก่ :  DEVICE_INFO's  DRIVER_INFO's  DRV_INTERFACE struct pointer                   
            //   ก่   : DEVICE_INFO struct pointer

            if (!IS_STATUS_SUCCESS(status) && (STATUS_NOT_CONFIGURED != status))
            {
                retStatus = status;
            }
        }
    }

    return retStatus;
}


/**
 ** @brief
 ** searches the list of known device drivers for given device type
 **
 ** @param[in]   Device - search for this device
 ** @param[out] p - NULL, if device could not be found, else pointer to device info of driver
 **
 ** @retval STATUS_SUCCESS  if device is available
 ** @retval STATUS_IOM_DEVICE_NOT_FOUND  if devive is not available
 **/
__STATIC STATUS getDeviceInfo(DEVICE_TYPE Device, PDEVICE_INFO* p)
{
    PDEVICE_INFO pRunner;
    STATUS status = STATUS_IOM_DEVICE_NOT_FOUND;

    if (0 != Device)
    {
        for (pRunner = pIFX_Iom_DeviceCfg; pRunner < pIFX_Iom_DeviceCfgEnd; pRunner++)
        {

            if (Device == pRunner->Identification)
            {
                *p = pRunner; // device found in list
                status = STATUS_SUCCESS;
                break;
            }
        }
    }

    return status;
}

/**
 ** @brief
 ** provides storage space for handles
 **
 ** This function supports creating a @ref HANDLE
 **
 ** @param[in]  Context information to be associated with a handle
 **
 ** @returns HANDLE
 **/
__STATIC HANDLE getHandleFromContext(PCONTEXT_INFO Context) // control code of operation to perform
{
    uint32_t i;
    PCONTEXT_INFO_ARRAY pTempContextInfoArray = IFX_IomContextInfoArray;
    PCONTEXT_INFO cp = NULL;

    IFX_Mutex_Lock(IFX_MUTEX_IOM_CONTEXT_INFO_ARRAY);

    // search for free info
    for (i = 0; i < DIMCONTEXTINFO; i++)
    {
        if (pTempContextInfoArray->ContextInfo[i].DriverContext.pDriverInfo == NULL)
        {
            cp = &pTempContextInfoArray->ContextInfo[i]; // empty entry found
            break;
        }

        if ((i == DIMCONTEXTINFO - 1) && (pTempContextInfoArray->Next != NULL)) // end of list reached ?
        {
            // end of array reached, start searching next allocated array, if available
            pTempContextInfoArray = pTempContextInfoArray->Next; // get next Array
            i = 0; // and restart at first array element
        }
    }

    if (cp == NULL) // no empty slot found -> create a new list with array elements
    {
        pTempContextInfoArray->Next = IFX_Alloc(sizeof(CONTEXT_INFO_ARRAY));
        pTempContextInfoArray = pTempContextInfoArray->Next;

        if (pTempContextInfoArray != NULL)
        {
            IFX_MemSet((void*)pTempContextInfoArray, 0, sizeof(CONTEXT_INFO_ARRAY));
            i = 0; // select first element in array of new element
        }
    }

    if (pTempContextInfoArray != NULL)
    {
        cp = &pTempContextInfoArray->ContextInfo[i]; // empty entry found
        cp->DriverContext.pDriverInfo = Context->DriverContext.pDriverInfo;
        cp->DriverContext.pContextInformation = Context->DriverContext.pContextInformation;
#if (IFX_CFG_MULTI_IO == 1)
        cp->TaskId = IFX_TmReadyQueue.Current->TaskId;
#endif // (IFX_CFG_MULTI_IO == 1)
    }

    IFX_Mutex_Unlock(IFX_MUTEX_IOM_CONTEXT_INFO_ARRAY);

    return (HANDLE)cp;
}

#ifdef DEBUG
/**
 ** @brief
 ** Checks the passed pointer of the handle is within the context
 **
 ** @param[in]  Handle the handle to check
 ** @param[in]  p      the context where this handle should be in
 **
 ** @returns uint8_t      TRUE if handle is valid
 **/
__STATIC uint8_t IFX_Iom_IsHandleValid(HANDLE Handle, PCONTEXT_INFO_ARRAY p)
{
    uint8_t isHandleValid = FALSE;

    do
    {
        isHandleValid = ((uint8_t*)Handle >= (uint8_t*)p) && ((uint8_t*)Handle < ((uint8_t*)p + sizeof(CONTEXT_INFO_ARRAY)))
            ? TRUE
            : FALSE;
        p = p->Next;
    } while (isHandleValid == FALSE && p != NULL);

    return isHandleValid;
}
#endif

#endif
/** @} */ // end of IFX_IO_MANAGER_GROUP

