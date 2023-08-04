#include "track.h"

uint8_t Track_Rx_Index;
uint8_t Track_Rx_Data_Temp[6];
uint8_t Track_Rx_Data[6];
uint8_t Track_Rx_Start_Flag;
int16_t X_PID_Output, Y_PID_Output;
PID X_PID, Y_PID;
int16_union X_Bias_Union, Y_Bias_Union;
int16_t X_Bias, Y_Bias;


void Track_Init()
{
    PID_Init(&X_PID);
    PID_Init(&Y_PID);

    PID_Set_Coefficients(&X_PID, 30, 0.3, 0);
    PID_Set_Coefficients(&Y_PID, 30, 0.3, 0);
    PID_Set_IntegrateLimit(&X_PID, 1e3f);
    PID_Set_IntegrateLimit(&Y_PID, 1e3f);
    
    void PID_Set_IntegrateLimit(PID *, float);
}

int16_t Get_X_Bias_From_Rx()
{
    X_Bias_Union.as_bytes[1] = Track_Rx_Data[1];
    X_Bias_Union.as_bytes[0] = Track_Rx_Data[2];
    return X_Bias_Union.as_int16;
}
int16_t Get_Y_Bias_From_Rx()
{
    Y_Bias_Union.as_bytes[1] = Track_Rx_Data[3];
    Y_Bias_Union.as_bytes[0] = Track_Rx_Data[4];
    return Y_Bias_Union.as_int16;
}

void Track_PID_Update(PID *pid, int16_t current, int16_t *output)
{
    Update_PI(pid, current, output);
}
