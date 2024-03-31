/*****************************************************************
 * FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : EEPROM_prog.c
 *  details : Source file for EEPROM Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include "STD_TYPES.h"

#include "TWI_int.h"

#include "EEPROM_priv.h"
#include "EEPROM_types.h"
#include "EEPROM_cfg.h"
#include "EEPROM_int.h"

/******************************************
  Local Data
 *******************************************/



/******************************************
  Global Data
 *******************************************/





/******************************************
  Local Functions  body
 *******************************************/


/******************************************
  Global Functions body
 *******************************************/

void HEEPROM_voidSendDataByte(u8 Copy_u8DataByte , u16 Copy_u16Address)
{
	/*local variable for EEPROM address*/
	u8 Local_u8Address;

	//1010 fixed
	//A2 pin configurable (either high or low)
	//last two bits is for page access
	Local_u8Address = (((EEPROM_FIXED_ADDRESS) |(A2_PIN<<2) |((Copy_u16Address>> 8) & 3)));

	/* 1)Sending start condition on the bus*/
	MTWI_enSendStartCondition();

	/* 2)Sending address of EEPROM with target page and write command*/
	MTWI_enSendSlaveAddressWithWriteCmd(Local_u8Address);


	/* 3)Sending target location of the EEPROM*/
	MTWI_enSendByte((u8)Copy_u16Address);

	/* 4)Sending target data to the specified location*/
	MTWI_enSendByte(Copy_u8DataByte);

	/* 5)Sending stop condition*/
	MTWI_voidSendStopCondition();
}

u8 HEEPROM_u8ReadDataByte(u16 Copy_u16Adderss)
{
	/* Local variable to get read data */
	u8 Local_u8Data;
	/*local variable for EEPROM address*/
	u8 Local_u8Address;

	//1010 fixed
	//A2 pin configurable (either high or low)
	//last two bits is for page access
	Local_u8Address = (((EEPROM_FIXED_ADDRESS) |(A2_PIN<<2) | ((Copy_u16Adderss >> 8) & 3)));

	/* 1)Sending start condition on the bus*/
	MTWI_enSendStartCondition();

	/* 2)Sending address of EEPROM with target page and write command*/
	MTWI_enSendSlaveAddressWithWriteCmd(Local_u8Address);

	/* 3)Sending target location of the EEPROM*/
	MTWI_enSendByte((u8)Copy_u16Adderss);

	/* 4)Sending repeated start condition*/
	MTWI_enSendStartCondition();

	/* 5)Sending address of EEPROM with target page and read command*/
	MTWI_enSendSlaveAddressWithReadCmd(Local_u8Address);

	/* 6)Reading from target location*/
	MTWI_enReceiveByteAck(&Local_u8Data);

	/* 5)Sending stop condition*/
	MTWI_voidSendStopCondition();

	return Local_u8Data;
}
