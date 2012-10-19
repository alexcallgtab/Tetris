#include "base.h"



void	piece0_rot1(t_env* env)
{
	env->pieces.piece0.x = env->pieces.piece0.x2;
	env->pieces.piece0.x1 = env->pieces.piece0.x2;
	env->pieces.piece0.x3 = env->pieces.piece0.x2;
	env->pieces.piece0.y = env->pieces.piece0.y2 + 2;
	env->pieces.piece0.y1 = env->pieces.piece0.y2 + 1;
	env->pieces.piece0.y3 = env->pieces.piece0.y2 - 1;
	env->pieces.piece0.rot = 1;
}

void	piece0_rot0(t_env* env)
{
	env->pieces.piece0.x = env->pieces.piece0.x2 - 2;
	env->pieces.piece0.x1 = env->pieces.piece0.x2 - 1;
	env->pieces.piece0.x3 = env->pieces.piece0.x2 + 1;
	env->pieces.piece0.y = env->pieces.piece0.y2;
	env->pieces.piece0.y1 = env->pieces.piece0.y2;
	env->pieces.piece0.y3 = env->pieces.piece0.y2;
	env->pieces.piece0.rot = 0;
}
