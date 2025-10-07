
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	enable = 0;
	speed = 0;
	
	fb_regulator.dt = 0.002;
	fb_regulator.k_p = 0.45;
	fb_regulator.k_i = 10.0;
	fb_regulator.max_abs_value=24;
	
	fb_motor.dt = 0.002;
	fb_motor.ke = 4;
	fb_motor.Tm = 0.03;
	
	fb_motor2.dt = 0.002;
	fb_motor2.ke = 4;
	fb_motor2.Tm = 0.03;
	
}

void _CYCLIC ProgramCyclic(void)
{	
	if (enable)
	{
		speed = 40.0;
	}
	else
	{
		speed = 0.0;
	}
	
	fb_regulator.e = speed - fb_motor.w;
	FB_regulator(&fb_regulator);
	
	fb_motor.u = 2*fb_regulator.u*fb_motor.ke;
	fb_motor2.u = speed*fb_motor2.ke;
	
	FB_motor(&fb_motor);
	FB_motor(&fb_motor2);
}

void _EXIT ProgramExit(void)
{

}

