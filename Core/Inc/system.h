#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "gpio.h"

#include "usart.h"

#include "string.h"
#include "stdlib.h"
#include "stdio.h"

#define PERIOD_INTERRUPT_TIM_HANDLER                htim1

#define SERVO_UART_HANDLER          huart3

#define TRACK_TASK_UART_HANDLER     huart2


typedef union {
    float as_float;
    uint8_t as_bytes[4];
} float_union;


typedef union {
    uint16_t as_uint16;
    uint8_t as_bytes[2];
} uint16_union;


float target_limit_float(float, float, float);
int target_limit_int(int, int, int);
float float_abs(float);

#endif
