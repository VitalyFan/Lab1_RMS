
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotorContr.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_regulator(struct FB_regulator* inst)
{
	REAL p_part = inst->e * inst->k_p;
	REAL i_part = inst->e * inst->k_i;
	
	inst->integrator.in = i_part;
	FB_Integrator(&inst->integrator);
	i_part = inst->integrator.out;
	
	REAL pi_reg = p_part + i_part;
	
	if (pi_reg > inst->max_abs_value) {
		inst->u = inst->max_abs_value;
		inst->integrator.out = inst->max_abs_value - p_part;
	} else if (pi_reg < -inst->max_abs_value) {
		inst->u = -inst->max_abs_value;
		inst->integrator.out = -inst->max_abs_value - p_part;
	} else {
		inst->u = pi_reg;
	}
	
	inst->iyOld = i_part;
}
