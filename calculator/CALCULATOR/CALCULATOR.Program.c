/*
 * CALCULATOR.Program.c
 *
 *  Created on: Apr 17, 2022 1:55:02 AM
 *      Author: mahmoud ramadan 
 */
#include"../LIB/LSTD_TYPES.h"
#include"../HAL/HCLCD/HCLCD_Config.h"
#include"../HAL/HCLCD/HCLCD_Interface.h"
#include"../HAL/HKPD/HKPD_Config.h"
#include"../HAL/HKPD/HKPD_Interface.h"
#include"CALCULATOR.Interface.h"
#include<util/delay.h>
#include<stdlib.h>

#define MAX_ARRAY    15
uint8 Global_buffer[MAX_ARRAY];
uint8 Global_buffer_Num1[7];
uint8 Global_buffer_Num2[7];
uint8 Global_bufferIndex=0;
volatile uint8 Global_Operator,GLobal_Num1,GLobal_Num2,Global_Result;

void CalcuVidInit(void)
{
	HKPD_VidInit();
	HAL_VidHCLCD_4BitModeInit();
	HAL_VidHCLCD_4BitModeSendCommand(0x01);
	HAL_VidHCLCD_4BitModeSetPosition(1,0);
	HAL_VidHCLCD_4BitModeWriteString((uint8*)"Welcome To");
	HAL_VidHCLCD_4BitModeSetPosition(2,0);
	HAL_VidHCLCD_4BitModeWriteString((uint8*)"Calculator");
	_delay_ms(1000);
	HAL_VidHCLCD_4BitModeSendCommand(0x01);
	uint8 Loc_KeypadState;
	while(1)
	{
		Loc_KeypadState=HKPD_uint8GetPressed();
		if(Loc_KeypadState!=HKPD_NOTPRESSED)
		{
			Calcu_vidPrintNum(Loc_KeypadState);
		}
		else
		{
			/*Do nothing*/
		}
	}
}
void Calcu_vidPrintNum(uint8 copy_uint8Num)
{

	if(copy_uint8Num == '=')
	{
		HAL_VidHCLCD_4BitModeWriteChar(copy_uint8Num);
		Global_buffer[Global_bufferIndex]=copy_uint8Num;
		Global_bufferIndex++;
		Calcu_Data(Global_buffer);
	}
	else
	{

		HAL_VidHCLCD_4BitModeWriteChar(copy_uint8Num);
		Global_buffer[Global_bufferIndex]=copy_uint8Num;
		Global_bufferIndex++;
	}

}
void Calcu_Data(uint8 *Global_buffer)
{
	uint8 Loc_count;
	uint8 count_max=0,num1_count=0,num2_count=0;
	/*Check for operation */
	for(Loc_count=0;Loc_count<=(Global_bufferIndex-1);Loc_count++)
	{
	if(Global_buffer[Loc_count]=='+'||Global_buffer[Loc_count]=='-'||Global_buffer[Loc_count]=='/'
			||Global_buffer[Loc_count]=='*')
	{
		Global_Operator=Global_buffer[Loc_count];
		count_max=Loc_count;
		count_max=count_max+1;
		/*Calculate numbers before operator*/
		for(num1_count=0;num1_count<(count_max-1);num1_count++)
		{
			Global_buffer_Num1[num1_count]=Global_buffer[num1_count];
		}
		/*Convert string to numbers*/
		GLobal_Num1=atoi(&Global_buffer_Num1);
	}
	if(Global_buffer[Loc_count]== '=')
	{
		for(count_max ; count_max <(Global_bufferIndex-1) ; count_max++)
		{
			Global_buffer_Num2[num2_count]=Global_buffer[count_max];
			num2_count++;
		}
		/*Convert string to numbers*/
		GLobal_Num2=atoi(&Global_buffer_Num2);
		break;
	}
	}
	Calcu_Operator(Global_Operator);
}
void Calcu_Operator(uint8 copy_uint8Operator)
{
	switch(copy_uint8Operator)
		{
		case'+':
		{
			Global_Result=GLobal_Num1+GLobal_Num2;
			break;
		}
		case'-':
		{
			Global_Result=GLobal_Num1-GLobal_Num2;
			break;
		}
		case'*':
		{
			Global_Result=GLobal_Num1*GLobal_Num2;
			break;
		}
		case'/':
		{
			Global_Result=GLobal_Num1/GLobal_Num2;
			break;
		}
		}
	Calcu_VidPrintResult(Global_Result);
}
void Calcu_VidPrintResult(uint8 copy_uint8result)
{

	HAL_VidHCLCD_4BitModeSendCommand(0x01);
	HAL_VidHCLCD_4BitModeSetPosition(1,0);
	HAL_VidHCLCD_4BitModeWriteString((uint8*)"Result =");
	HAL_VidHCLCD_4BitModeSetPosition(2,0);
	HAL_VidHCLCD_4BitModeWriteNumber(copy_uint8result);
	_delay_ms(4000);
	HAL_VidHCLCD_4BitModeSendCommand(0x01);

}
