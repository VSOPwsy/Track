#include "track.h"

uint8_t Track_Rx_Index;
uint8_t Track_Rx_Data_Temp[6];
uint8_t Track_Rx_Data[6];
uint8_t Track_Rx_Start_Flag;

uint16_union X_Bias_Union, Y_Bias_Union;
uint16_t X_Bias, Y_Bias;

uint16_t Get_X_Bias_From_Rx()
{
    X_Bias_Union.as_bytes[0] = Track_Rx_Data[1];
    X_Bias_Union.as_bytes[1] = Track_Rx_Data[2];
    return X_Bias_Union.as_uint16;
}
uint16_t Get_Y_Bias_From_Rx()
{
    Y_Bias_Union.as_bytes[0] = Track_Rx_Data[3];
    Y_Bias_Union.as_bytes[1] = Track_Rx_Data[4];
    return Y_Bias_Union.as_uint16;
}
