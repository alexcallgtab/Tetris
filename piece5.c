#include "base.h"

void	piece5_rot1(t_env* env)
{
	env->pieces.piece5.x = env->pieces.piece5.x2 + 1;
	env->pieces.piece5.x1 = env->pieces.piece5.x2 + 1;
	env->pieces.piece5.x3 = env->pieces.piece5.x2;
	env->pieces.piece5.y = env->pieces.piece5.y2;
	env->pieces.piece5.y1 = env->pieces.piece5.y2 - 1;
	env->pieces.piece5.y3 = env->pieces.piece5.y2 + 1;
	env->pieces.piece5.rot = 1;
}

void	piece5_rot0(t_env* env)
{
	env->pieces.piece5.x = env->pieces.piece5.x2 + 1;
	env->pieces.piece5.x1 = env->pieces.piece5.x2;
	env->pieces.piece5.x3 = env->pieces.piece5.x2 - 1;
	env->pieces.piece5.y = env->pieces.piece5.y2;
	env->pieces.piece5.y1 = env->pieces.piece5.y2 - 1;
	env->pieces.piece5.y3 = env->pieces.piece5.y2 - 1;
	env->pieces.piece5.rot = 0;
}
