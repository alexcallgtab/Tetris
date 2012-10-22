#include "base.h"

void	piece5_rot1(t_env* env)
{
	env->piece.x = env->piece.x2 + 1;
	env->piece.x1 = env->piece.x2 + 1;
	env->piece.x3 = env->piece.x2;
	env->piece.y = env->piece.y2;
	env->piece.y1 = env->piece.y2 - 1;
	env->piece.y3 = env->piece.y2 + 1;
	env->piece.rot = 1;
}

void	piece5_rot0(t_env* env)
{
	env->piece.x = env->piece.x2 + 1;
	env->piece.x1 = env->piece.x2;
	env->piece.x3 = env->piece.x2 - 1;
	env->piece.y = env->piece.y2;
	env->piece.y1 = env->piece.y2 - 1;
	env->piece.y3 = env->piece.y2 - 1;
	env->piece.rot = 0;
}
