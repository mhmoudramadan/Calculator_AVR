/*
 * CALCULATOR.Interface.h
 *
 *  Created on: Apr 17, 2022 1:54:42 AM
 *      Author: mahmoud ramadan 
 */

#ifndef CALCULATOR_CALCULATOR_INTERFACE_H_
#define CALCULATOR_CALCULATOR_INTERFACE_H_


void CalcuVidInit(void);
void Calcu_Data(uint8 Global_buffer[]);
void Calcu_Operator(uint8 copy_uint8Operator);
void Calcu_VidPrintResult(uint8 copy_uint8result);
void Calcu_vidPrintNum(uint8 copy_uint8Num);

#endif /* CALCULATOR_CALCULATOR_INTERFACE_H_ */
