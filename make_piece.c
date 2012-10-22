#include "base.h"


void	init_piece0(t_env* env)
{
	env->piece.x = 20;
	env->piece.x1 = 21;
	env->piece.x2 = 22;
	env->piece.x3 = 23;
	env->piece.y = 7;
	env->piece.y1 = 7;
	env->piece.y2 = 7;
	env->piece.y3 = 7;
	env->piece.rot = 0;
	env->piece.rot1 = piece0_rot1;
	env->piece.rot2 = piece0_rot2;
}

void	init_piece1(t_env* env)
{
	env->piece.x = 22;
	env->piece.x1 = 21;
	env->piece.x2 = 22;
	env->piece.x3 = 23;
	env->piece.y = 8;
	env->piece.y1 = 7;
	env->piece.y2 = 7;
	env->piece.y3 = 7;
	env->piece.rot = 0;
	env->piece.rot1 = piece1_rot1;
	env->piece.rot2 = piece1_rot2;
	env->piece.rot3 = piece1_rot3;
	env->piece.rot4 = piece1_rot4;
}
