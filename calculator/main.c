/*
 * main.c
 *
 *  Created on: Apr 17, 2022 3:41:14 AM
 *      Author: mahmoud ramadan 
 */

#include"LIB/LSTD_TYPES.h"
#include"MCAL/MDIO/MDIO_Interface.h"
#include"CALCULATOR/CALCULATOR.Interface.h"
#include"HAL/HCLCD/HCLCD_Config.h"

#ifndef F_CPU
#define F_CPU  16000000UL
#endif
#include<util/delay.h>

int main(void)
{
	/*initialize LCD Pin*/
	MDIO_Errorstate_SetPinDirection(HCLCD_ControlPort,RS_PIN,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_ControlPort,RW_PIN,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_ControlPort,E_PIN,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_DataPort,PIN4,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_DataPort,PIN5,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_DataPort,PIN6,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_DataPort,PIN7,PIN_OUTPUT);
//	HAL_VidHCLCD_4BitModeInit();
	/*Initialize Calculator*/
	CalcuVidInit();
	while(1)
	{

	}
	return 0;
}
