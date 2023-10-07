#include "utility.h"
#include "main.h"

float mappingValue(float value,float preMin,float preMax,float postMin,float postMax){
	return value-preMin/(preMax-preMin)*(postMax-postMin);
}
int threasHold(float input,int threasholdCnt,float min,float max){
	float threasholdRange = (max-min )/(float)threasholdCnt;
	int returnValue = (int)((input-min)/threasholdRange);
	return threasholdRange;
}
SampleData createSample(int size){
	SampleData sample;
	sample.size = size;
	sample.datas = malloc(4*size);
	sample.total = 0;
	sample.average = 0;
	sample.index = 0;
	sample.count = 0;
	for(int i=0;i<size;i++){
		*(sample.datas+i) = 0;
	}
	return sample;
}
void AppendSample(float input,SampleData* st){
	if(st->count<st->size)
		st->count++;
	st->total +=input-st->datas[st->index];
	st->datas[st->index]=input;
	st->average = st->total/st->count;
	st->index=st->index!=st->size?st->index+1:0;
}
void Toggle(bool* b){
	*b=!*b;
}
bool digitalRead(GPIO_TypeDef* GPIOx, uint16_t pin){
	return HAL_GPIO__ReadPin(GPIOx,pin) == GPIO_PIN_SET;
}
void digitalWrite(GPIO_TypeDef* GPIOx, uint16_t pin,bool b){
	//Example GPIOB,GPIO_PIN_0 ,GPIO_PIN_RESET/SET
	HAL_GPIO_WritePin( GPIOx,pin ,b);
}
char getChar(){
	char ch1;
	while(__HAL_UART_GET_FLAG(getUSART(),UART_FLAG_RXNE)== RESET){}
	HAL_UART_Receive(getUSART(), (uint8_t*) &ch1, 1, 1000);
	return ch1;
}
void printOut(char* str){

	while(__HAL_UART_GET_FLAG(getUSART(),UART_FLAG_TC)==RESET){}
		HAL_UART_Transmit(getUSART(), (uint8_t*) str,strlen(str),1000);

}
/*
 * utiliity.c
 *
 *  Created on: Oct 7, 2023
 *      Author: vorapolpromwan
 */


