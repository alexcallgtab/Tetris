#include "base.h"


void	piece1_rot1(t_env* env)
{
	env->pieces.piece1.x = env->pieces.piece0.x2 - 1;
	env->pieces.piece1.x1 = env->pieces.piece0.x2;
	env->pieces.piece1.x3 = env->pieces.piece0.x2;
	env->pieces.piece1.y = env->pieces.piece0.y2;
	env->pieces.piece1.y1 = env->pieces.piece0.y2 + 1;
	env->pieces.piece1.y3 = env->pieces.piece0.y2 - 1;
	env->pieces.piece1.rot = 1;
}


void	piece1_rot2(t_env* env)
{
	env->pieces.piece1.x = env->pieces.piece0.x2;
	env->pieces.piece1.x1 = env->pieces.piece0.x2 + 1;
	env->pieces.piece1.x3 = env->pieces.piece0.x2 - 1;
	env->pieces.piece1.y = env->pieces.piece0.y2 - 1;
	env->pieces.piece1.y1 = env->pieces.piece0.y2;
	env->pieces.piece1.y3 = env->pieces.piece0.y2;
	env->pieces.piece1.rot = 2;
}



void	piece1_rot3(t_env* env)
{
	env->pieces.piece1.x = env->pieces.piece0.x2 + 1;
	env->pieces.piece1.x1 = env->pieces.piece0.x2;
	env->pieces.piece1.x3 = env->pieces.piece0.x2;
	env->pieces.piece1.y = env->pieces.piece0.y2;
	env->pieces.piece1.y1 = env->pieces.piece0.y2 + 1;
	env->pieces.piece1.y3 = env->pieces.piece0.y2 - 1;
	env->pieces.piece1.rot = 3;
}


void	piece1_rot4(t_env* env)
{
	env->pieces.piece1.x = env->pieces.piece0.x2 + 1;
	env->pieces.piece1.x1 = env->pieces.piece0.x2 - 1;
	env->pieces.piece1.x3 = env->pieces.piece0.x2;
	env->pieces.piece1.y = env->pieces.piece0.y2;
	env->pieces.piece1.y1 = env->pieces.piece0.y2;
	env->pieces.piece1.y3 = env->pieces.piece0.y2 + 1;
	env->pieces.piece1.rot = 0;
}
