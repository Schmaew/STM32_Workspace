/*
 * my_basic.h
 *
 *  Created on: Sep 28, 2023
 *      Author: sunsu
 */

#ifndef __MY_BASIC_H_
#define __MY_BASIC_H_

#include "usart.h"
#include "i2c.h"
#include "stdint.h"
#include "stm32f7xx.h"

typedef struct _PwmInfo
{
	TIM_HandleTypeDef *timer;
	uint32_t timerChannel;
	GPIO_TypeDef *pinGroup;
	uint16_t pin;
	float dutyCycle;
} PwmInfo;

typedef struct _GpioInfo
{
	GPIO_TypeDef *group;
	uint16_t pin;
} GpioInfo;

void printOut(const char *text);
void printOutLine(const char *text);
void receiveUserInput(char *rxData);
void delay(uint32_t delay);

int average8(int newValue);
int average16(int newValue);

void AM2320_setCommand(uint8_t *cmdBuffer);
void AM2320_startSensor(I2C_HandleTypeDef *hi2c, uint8_t *cmdBuffer, uint8_t *dataBuffer);
void AM2320_getTemperatureAndHumidity(float *temperature, float *humidity, uint8_t dataBuffer[8]);
uint16_t AM2320_CRC16_2(uint8_t *ptr, uint8_t length);
void checkI2cAddress(I2C_HandleTypeDef *hi2c);


#endif /* __MY_BASIC_H_ */
