/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
 *  file    : TIMER0_Lcfg.c
 *  details : Source file for link time configurations TIMER0 Driver.
 *****************************************************************/

/******************************************
  INCLUDES
 *******************************************/
#include "TIMER0_types.h"
#include "TIMER0_cfg.h"


/******************************************
  Global Data
 *******************************************/
const TIMER0_ConfigType TIMER0_xConfig = {TIMER0_CTC_MODE,OC0_DISCONNECTED,TIMER0_1024_PRESCALER};
