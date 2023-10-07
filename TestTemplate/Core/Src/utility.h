#pragma once
#include <stdbool.h>
#include "main.h"

UART_HandleTypeDef* getUSART();

float mappingValue(float value,float preMin,float preMax,float postMin,float postMax);
int threasHold(float input,int threasholdCnt,float min,float max);
typedef struct SampleDataStruct{
	int size;
	float* datas;
	float total ;
	float average ;
	int index ;
	int count;

}SampleData;
SampleData createSample(int size);
void AppendSample(float input,SampleData* st);
void Toggle(bool* b);
bool digitalRead(GPIO_TypeDef* GPIOx, uint16_t pin);
void digitalWrite(GPIO_TypeDef* GPIOx, uint16_t pin,bool b);
char getChar();
void printOut(char* str);
/*
 * utiliity.c
 *
 *  Created on: Oct 7, 2023
 *      Author: vorapolpromwan
 */


/*
 * utility.h
 *
 *  Created on: Oct 7, 2023
 *      Author: vorapolpromwan
 */

#ifndef SRC_UTILITY_H_
#define SRC_UTILITY_H_



#endif /* SRC_UTILITY_H_ */
