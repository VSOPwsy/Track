#ifndef __PID_H
#define __PID_H


#include "system.h"

typedef struct{
    float desired;
    float error;
    float previous_error;
    float integral;
    float integrate_limit;
    float Kp, Ki, Kd;
} PID;

void PID_Init(PID *);

void PID_Set_Kp(PID *, float);
void PID_Set_Ki(PID *, float);
void PID_Set_Kd(PID *, float);

void PID_Set_Coefficients(PID *, float, float, float);

void PID_Set_Target(PID *, float);

void PID_Set_IntegrateLimit(PID *, float);
void Update_PI(PID *, int16_t current, int16_t *output);

#endif
