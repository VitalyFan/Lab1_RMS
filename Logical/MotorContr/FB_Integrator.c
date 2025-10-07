
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotorContr.h"
#ifdef __cplusplus
	};
#endif
/* intrigal */
void FB_Integrator(struct FB_Integrator* inst)
{
	inst->dt=0.002;
	inst->out = inst->dt * inst->in + inst->state;
	inst->state = inst->out;
	
}