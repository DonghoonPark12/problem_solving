/* -------------------------------------------------------------- */
/* MCU�� ���� GPIO�� �о� ���̴� �Լ�
/* 
/* 
/* -------------------------------------------------------------- */



/* -------------------------------------------------------------- */
/* 
/* 
/* 
/* -------------------------------------------------------------- */

/* Lib_CountUp_ICU.c */
/* Task�� �� ������ ī��Ʈ�� ���� ��Ų��. */

/* 2byte Count Up Function */
U16		u16g_LibCountUp( U16 u16t_Count, U16 u16t_Max )
{
	if( u16t_Count < u16t_Max )
	{
		u16t_Count++;
	}
	else
	{
		u16t_Count = u16t_Max;
	}
	
	return( u16t_Count );
}

/* 4byte Count Up Function */
U32		u32g_LibCountUp( U32 u32t_Count, U32 u32t_Max )
{
	if( u32t_Count < u32t_Max )
	{
		u32t_Count++;
	}
	else
	{
		u32t_Count = u32t_Max;
	}
	return ( u32t_Count );
}

/* 1byte Count Down Function */
U8		u8g_LibCountUp( U8 u8t_Count, U8 u8t_Min )
{
	if( u8t_Count > u8t_Min )
	{
		u8t_Count--;
	}
	else
	{
		u8t_Count = u8t_Min;
	}
	return ( u8t_Count );
}