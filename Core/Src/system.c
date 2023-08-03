#include "system.h"



float target_limit_float(float insert, float low, float high)
{
    if (insert < low)
        return low;
    else if (insert > high)
        return high;
    else
        return insert;	
}

int target_limit_int(int insert, int low, int high)
{
    if (insert < low)
        return low;
    else if (insert > high)
        return high;
    else
        return insert;	
}

float float_abs(float insert)
{
    if (insert < 0)
        return -insert;
    else
        return insert;	
}
