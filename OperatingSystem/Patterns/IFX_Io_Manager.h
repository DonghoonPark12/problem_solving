
#ifndef IFX_IO_MANAGER_H
#define IFX_IO_MANAGER_H
/** @addtogroup IFX_IO_MANAGER_GROUP
 *  @{
 */

 /*  includes
  ****************************************************************/
#include "IFX_Framework.h"
#include "../IFX_Ioctl/IFX_Ioctl_Defs.h"
#include "../IFX_Tasks/IFX_Tasks.h"

  /*  pragmas
   ****************************************************************/

   /*  defines
    ****************************************************************/
    /** @brief initial capacity of IO Manger internal driver context memory
     **
     ** @see gContextInfoArray
     **/
#define DIMCONTEXTINFO 10

     /** @defgroup init_stages Initialization stages
     The available initialization stages for the drivers */
     //@{
#define IFX_IOM_NOT_INITIALIZED               0
#define IFX_IOM_INI_STAGE_1                   1
#define IFX_IOM_INI_STAGE_2                   2
#define IFX_IOM_INI_STAGE_MAX                 IFX_IOM_INI_STAGE_2
//@}


/*  typedefs
 ****************************************************************/

 /** @brief struct holding device driver information relevant for IO Manager
  **
  ** This struct keeps the basic information for the IO Manager
  ** @see DRIVER_CONTEXT
  **/
typedef struct _DeviceInfo
{
    uint8_t       InitStage;          ///< stage in which the driver should be initialized
    DEVICE_TYPE Identification;     ///< field for Driver identification, e.g. device name like DEV_Nvm
    DRIVER_INFO DriverInfo;         ///< holding the driver infromation relevant for the IO Manager, e.g. references to DriverOpen() DriverClode() etc
} DEVICE_INFO, * PDEVICE_INFO;

/** @brief IO Manager maintained driver context
 **
 ** This struct keeps the context information for the IO Manager
 ** @see DRIVER_CONTEXT
 **/
typedef struct _iom_context_info_
{
    DRIVER_CONTEXT DriverContext;   ///< current driver context information stored in IO Manager space
    IFX_TASK_IDS   TaskId;          ///< information about task holding this handle
} CONTEXT_INFO, * PCONTEXT_INFO;


/** @brief storage space for context information
 **
 ** This struct defines the layout of the storage space
 ** where the IO Manager keeps all driver context information
 **
 ** @see CONTEXT_INFO
 ** @see DRIVER_CONTEXT
 **/
typedef struct _ContextInfoArray_
{
    CONTEXT_INFO ContextInfo[DIMCONTEXTINFO];
    struct _ContextInfoArray_* Next;
} CONTEXT_INFO_ARRAY, * PCONTEXT_INFO_ARRAY;

/** @brief interface type for a drivers initialization interface
 **
 ** This function prototype definition must be implemented by each driver
 ** and represents the driver entry during system initialization.
 ** The function implementation must be referenced in the device configuration and
 ** will be called during each reset.
 ** The implemetation of such a driver initialization function must fill
 ** all fields of the passed pDriverInfo structure.
 **
 ** 이 함수 프로토타입 정의는 각 드라이버에 의해 구현되어야 하며, 시스템 초기화 중 드라이버 항목을 나타냅니다.
 ** 기능 수현은 장치구성(configuration)에서 참조되어야 하며, 각 Reset 중에 호출된다.
 ** 이러한 드라이버 초기화 기능을 구현하려면, 드라이버 초기 함수는 pDriverInfo(IFX_IoCtl_Defs.h) 구조체를 채워야 한다.
 ** @see DRIVER_INFO
 **/
typedef
STATUS(*PDRIVER_INIT)(PDRIVER_INFO pDriverInfo) //
__REENTRANT;

/** @brief interface type for a drivers open interface
 **
 ** This function prototype definition must be implemented by each driver
 ** and represents the driver open during system runtime. The
 ** function implementation must be referenced by the driver interface structure.
 ** The implemetation of such a driver function can be used to create an instance of the
 ** driver.
 **
 ** @sa DRIVER_INFO, PDRIVER_CLOSE, PDRIVER_CANCEL_IO, PDRIVER_IOCTRL, PDRIVER_SHORT_IOCTRL
 **/
typedef
STATUS(*PDRIVER_OPEN) (
    PDRIVER_CONTEXT DriverContext, // share mode
    IN uint32_t Mode
    ) __REENTRANT;

/** @brief interface type for a drivers close interface
 **
 ** This function prototype definition must be implemented by each driver
 ** and represents the driver close during system runtime. The
 ** function implementation must be referenced by the driver interface structure.
 ** The implemetation of such a driver function shall be used to cleanup a instance.
 **
 ** @sa DRIVER_INFO, PDRIVER_OPEN, PDRIVER_CANCEL_IO, PDRIVER_IOCTRL, PDRIVER_SHORT_IOCTRL
 **/
typedef STATUS
(*PDRIVER_CLOSE)(PDRIVER_CONTEXT DriverContext)
__REENTRANT;

/** @brief optional interface type for a drivers cancle IO interface
 **
 ** This function prototype definition can optionally be implemented by a driver
 ** and represents the driver cancle IO during system runtime. If provided, the
 ** function implementation must be referenced by the driver interface structure.
 ** The implemetation of such a driver function is used by the IO Manager to in case
 ** of a reset event. If called, the driver can handle a hardware module, e.g. shutting
 ** up a communication stream.
 **
 ** @sa DRIVER_INFO, PDRIVER_OPEN, PDRIVER_CLOSE, PDRIVER_IOCTRL, PDRIVER_SHORT_IOCTRL
 **/
typedef STATUS
(*PDRIVER_CANCEL_IO)(PDRIVER_CONTEXT DriverContext)
__REENTRANT;

/** @brief interface type for a drivers IOCTL function with reduced parameter set
 **
 ** This function prototype definition shall be used by the OS or application to
 ** access driver functionality. This function prototype has less parameter to
 ** improve the calles code footprint and execution performance.
 **
 ** @sa DRIVER_INFO, PDRIVER_OPEN, PDRIVER_CLOSE, PDRIVER_IOCTRL, PDRIVER_CANCEL_IO
 **/
typedef STATUS
(*PDRIVER_SHORT_IOCTRL)(PDRIVER_CONTEXT DriverContext,// handle to a device
    uint32_t ControlCode, // control code of operation to perform
    void* InBuffer, // pointer to buffer to supply input data
    uint32_t InLength // size, in bytes, of input buffer
    )
    __REENTRANT;

/** @brief interface type for a drivers IOCTL function with complete parameter set
 **
 ** This function prototype definition shall be used by the OS or application to
 ** access driver functionality. This function prototype provides the complete parameter set to
 ** the driver interface.
 **
 ** @sa DRIVER_INFO, PDRIVER_OPEN, PDRIVER_CLOSE, PDRIVER_CANCEL_IO, PDRIVER_SHORT_IOCTRL
 **/
typedef
STATUS
(*PDRIVER_IOCTRL) (
    PDRIVER_CONTEXT DriverContext,// handle to a device
    uint32_t ControlCode, // control code of operation to perform
    IN IOCTL_PARAMETER* InParameter,
    OUT IOCTL_PARAMETER* OutParameter
    ) __REENTRANT;


/**
  This macro creates DEVICE_INFO object in NVM and
  a pointer to (a void pointer in RAM which is referenced as ppDeviceInformation)
  within the DEVICE_INFO object.

  This pointer to a void pointer can be updated in the driver init if required.

  On SLE70:
  It is required that the DEVICE_INFO object, which is located in NVM, is placed in a special
  section. So before using the macro the userclass has to be changed so that the DEVICE_INFO
  object will be placed there.

  On SLE90:
  For the SLE90 platform the placement is handled by the macro.

  해당 매크로는 'DEVICE_INFO 객체'와
  DEVICE_INFO 객체 내에서 ppDeviceInformation로 참조되는 RAM의 void 포인터에 대한 포인터를
  NVM에 생성한다.
*/
#define IFX_DEVICE_LIST_ENTRY(devId, stage, pInterfaceStruct)            \
    static void *IFX_Iom_DeviceInfoMap_##devId; \
    static SECT90(ifx_device_list) const DEVICE_INFO IFX_Iom_DeviceCfg_##devId = { (stage), (devId), {&IFX_Iom_DeviceInfoMap_##devId, (DRV_INTERFACE*)(pInterfaceStruct)}}


/*  debug definitions
 ****************************************************************/

 /*  prototypes
  ****************************************************************/
STATUS IFX_Iom_Init(void);
STATUS IFX_Iom_Device_Init(void);
HANDLE IFX_Device_Open(DEVICE_TYPE device, uint32_t mode);
// for further info about the structure of in and outbuffer
// look in the specification of the specific device in this file
STATUS IFX_Device_IoCtl(IN  HANDLE              Handle,
    IN  uint32_t              ControlCode,
    IN  IOCTL_PARAMETER* InParameter,
    OUT IOCTL_PARAMETER* OutParameter) __LEVEL_CALL;
STATUS IFX_Device_Close(HANDLE Handle);
STATUS IoForceCloseHandlesFromTaskId(IFX_TASK_IDS TaskId);

/** @} */// end of IFX_IO_MANAGER_GROUP
#endif /* IFX_IO_MANAGER_H */

