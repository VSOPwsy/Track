#ifndef __TRACK_H
#define __TRACK_H


#include "system.h"
#include "usart.h"

extern uint8_t Track_Rx_Index;
extern uint8_t Track_Rx_Data_Temp[6];
extern uint8_t Track_Rx_Data[6];
extern uint8_t Track_Rx_Start_Flag;

extern uint16_union X_Bias_Unino, Y_Bias_Union;
extern uint16_t X_Bias, Y_Bias;

uint16_t Get_X_Bias_From_Rx(void);
uint16_t Get_Y_Bias_From_Rx(void);

#endif
