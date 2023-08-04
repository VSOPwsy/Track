#ifndef __TRACK_H
#define __TRACK_H


#include "system.h"
#include "usart.h"
#include "pid.h"


extern uint8_t Track_Rx_Index;
extern uint8_t Track_Rx_Data_Temp[6];
extern uint8_t Track_Rx_Data[6];
extern uint8_t Track_Rx_Start_Flag;

extern int16_union X_Bias_Unino, Y_Bias_Union;
extern int16_t X_Bias, Y_Bias;

int16_t Get_X_Bias_From_Rx(void);
int16_t Get_Y_Bias_From_Rx(void);

extern PID X_PID, Y_PID;
extern int16_t X_PID_Output, Y_PID_Output;

void Track_Init(void);
void Track_PID_Update(PID *pid, int16_t current, int16_t *output);


#endif
