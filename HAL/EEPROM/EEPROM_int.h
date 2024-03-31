/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : EEPROM_int.h
*  details : Header file for interface EEPROM Driver.
*****************************************************************/
#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"

/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL DATA TYPES AND STRUCTURES
*******************************************/

/******************************************
  GLOBAL DATA PROTOTYPES
*******************************************/

/******************************************
   GLOBAL FUNCTIONS PROTOTYPES
*******************************************/
void HEEPROM_voidSendDataByte(u8 Copy_u8DataByte , u16 Copy_u16Address);

u8 HEEPROM_u8ReadDataByte(u16 Copy_u16Adderss);

#endif /* EEPROM_INT_H_ */
