
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotorContr.h"
#ifdef __cplusplus
	};
#endif

void FB_motor(struct FB_motor* inst)
{
	REAL bf1 = (inst->u) / inst->ke - inst->w;
	REAL bf2 = bf1 / inst->Tm;
	
	inst->w_integrator.in = bf2;
	FB_Integrator(&inst->w_integrator);
	inst->w = inst->w_integrator.out;
	
	inst->phi_integrator.in = inst->w;
	FB_Integrator(&inst->phi_integrator);
	inst->phi = inst->phi_integrator.out;
}
