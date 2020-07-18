IFX_CMD_FUNC* func;

typedef IFX_CMD_RESULT(IFX_CMD_FUNC)(IFX_CMD_IN_PARAMS* pInParams, IFX_CMD_OUT_PARAMS* pOutParams);


IFX_Command_Handler_ExecuteCmd(commandEntryHandle, &inParams, &outParams);

IFX_CMD_RESULT IFX_Command_Handler_ExecuteCmd(IFX_IN IFX_CMD_ENTRY_HANDLE commandEntryHandle, IFX_IN IFX_CMD_IN_PARAMS* pInParams, IFX_OUT IFX_CMD_OUT_PARAMS* pOutParams)
{
    const IFX_COMMAND_HANDLER_ENTRY* pCmdHandlerEntry;
    uint16_t isoSwReturnCode;
    uint8_t secureMessagingIndicated;
    IFX_CMD_RESULT result;

    secureMessagingIndicated = FALSE;

    // If handle is invalid, return error code
    if (commandEntryHandle == INVALID_IFX_CMD_ENTRY_HANDLE)
    {
        IFX_Command_Handler_WriteReturnCode(ISOSW_UNKNOWN_INS, pInParams, pOutParams);
        result = IFX_CMD_RESULT_PASS;
    }
    else
    {
        if (pInParams->length >= IFX_CMD_MINLEN)
        {
            secureMessagingIndicated = (IFX_Command_Handler_CheckForSecureMessaging(pInParams->pData[APDU_CLA]) == IFX_CMD_RESULT_PASS);
        }

        // Call unwrap command if secure messaging is indicated
        if (secureMessagingIndicated)
        {
            unwrapReq(pInParams);
        }

        pCmdHandlerEntry = (IFX_COMMAND_HANDLER_ENTRY*)commandEntryHandle;

        // Check if apdu is correct and return an error code if fails
        isoSwReturnCode = checkApduLength(pCmdHandlerEntry, pInParams);

        if (isoSwReturnCode != ISOSW_SUCCESS)
        {
            IFX_Command_Handler_WriteReturnCode(isoSwReturnCode, pInParams, pOutParams);
            result = IFX_CMD_RESULT_PASS;
        }
        else
        {
            // Call command function
            result = (*pCmdHandlerEntry->func)(pInParams, pOutParams); // ---> After that go to SCP Driver

            SCHEDULE_BARRIER_ISSC_WORKAROUND();
        }
    }

    // Handle secure messaging if indicated and executed function
    // did not indicate anything else then IFX_CMD_RESULT_PASS
    if (secureMessagingIndicated && (result == IFX_CMD_RESULT_PASS))
    {
        wrapRes(pOutParams);
    }

    return result;
}
