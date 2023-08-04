#include "pid.h"

void PID_Init(PID *pid)
{
    pid->Kp = 0;
    pid->Ki = 0;
    pid->Kd = 0;

    pid->desired = 0;
    pid->error = 0;
    pid->previous_error = 0;
    pid->integral = 0;

    pid->integrate_limit = 1e3f;
}

void PID_Set_Kp(PID *pid, float Kp)
{
  pid->Kp = Kp;
}

void PID_Set_Ki(PID *pid, float Ki)
{
  pid->Ki = Ki;
}

void PID_Set_Kd(PID *pid, float Kd)
{
  pid->Kd = Kd;
}

void PID_Set_Coefficients(PID *pid, float Kp, float Ki, float Kd)
{
  pid->Kp = Kp;
  pid->Ki = Ki;
  pid->Kd = Kd;
}

void PID_Set_Target(PID *pid, float desired)
{
  pid->desired = desired;
}

void PID_Set_IntegrateLimit(PID *pid, float limit)
{
  pid->integrate_limit = limit;
}

void Update_PI(PID *pid, int16_t current, int16_t *output)
{
  pid->error = pid->desired - current;
  pid->integral += pid->error;
  if (pid->integral > pid->integrate_limit)
  {
    pid->integral = pid->integrate_limit;
  }
  else if (pid->integral < - pid->integrate_limit)
  {
    pid->integral = - pid->integrate_limit;
  }

  *output = (int)(pid->Kp*pid->error + pid->Ki*pid->integral);
}
