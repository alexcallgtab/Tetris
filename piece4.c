 #include "base.h"

void	piece4_rot1(t_env* env)
{
	env->pieces.piece4.x = env->pieces.piece5.x2;
	env->pieces.piece4.x1 = env->pieces.piece5.x2 + 1;
	env->pieces.piece4.x3 = env->pieces.piece5.x2 + 1;
	env->pieces.piece4.y = env->pieces.piece5.y2 + 1;
	env->pieces.piece4.y1 = env->pieces.piece5.y2;
	env->pieces.piece4.y3 = env->pieces.piece5.y2 - 1;
	env->pieces.piece4.rot = 1;
}

void	piece4_rot0(t_env* env)
{
	env->pieces.piece4.x = env->pieces.piece5.x2 - 1;
	env->pieces.piece4.x1 = env->pieces.piece5.x2;
	env->pieces.piece4.x3 = env->pieces.piece5.x2 + 1;
	env->pieces.piece4.y = env->pieces.piece5.y2;
	env->pieces.piece4.y1 = env->pieces.piece5.y2 - 1;
	env->pieces.piece4.y3 = env->pieces.piece5.y2 - 1;
	env->pieces.piece4.rot = 0;
}
