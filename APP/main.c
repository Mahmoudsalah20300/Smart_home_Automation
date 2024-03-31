/*
 * main.c
 *
 *  Created on: Feb 19, 2023
 *      Author: Mahmoud_Ali
 */
#include <util/delay.h>
#include <string.h>
#include "STD_TYPES.h"
#include "Led_int.h"
#include "PB_int.h"
#include "Dio_int.h"
#include "Port_int.h"
#include "CLCD_int.h"
#include "KPD_int.h"
#include "UART_int.h"
#include "EXTI_int.h"
#include "GIE_int.h"
#include "TIMER1_int.h"
#include "ULTRASONIC_int.h"
#include "OS_int.h"
#include "PWM0_int.h"
#include "DCMOTOR_int.h"
#include "TEMP_int.h"
#include "SPI_int.h"
#include "TWI_int.h"
#include "EEPROM_int.h"
#include "RTC_int.h"
void Receive(void);
char_t *Global_Buffer;

extern const Port_Configtype Port_ConfigArr[PORT_PINS_CONFIG_ARR_SIZE];
extern const RTC_TimeType RTC_xTime;
extern const RTC_DateType RTC_xDate;
void main(void)
{
	RTC_TimeType Time;
	RTC_DateType Date;
	MPort_voidInit(Port_ConfigArr);
	HRTC_voidInit();
	HCLCD_voidInit();
	HRTC_voidSetCurrentTime(&RTC_xTime);
	HRTC_voidSetCurrentDate(&RTC_xDate);
	while(1)
	{
		Time=HRTC_xGetCurrentTime();
		HCLCD_voidIntegerToString(Time.Hours);
		HCLCD_voidSendData(':');
		HCLCD_voidIntegerToString(Time.Minutes);
		HCLCD_voidSendData(':');
		HCLCD_voidIntegerToString(Time.Seconds);
		HCLCD_voidGotoXY(1, 0);
		Date = HRTC_XGetCurrentDate();
		HCLCD_voidSendString(Date.Date);
		HCLCD_voidSendData('/');
		HCLCD_voidIntegerToString(Date.Mounth);
		HCLCD_voidSendData('/');
		HCLCD_voidIntegerToString(Date.Year);
		HCLCD_voidSendData(' ');
		HCLCD_voidSendString(&Date.Day);
		_delay_ms(1000);
		HCLCD_voidClearScreen();
	}
}

void Receive(void)
{
	//MUART_enReceiveByteAsync(Global_Buffer, Receive);
}

