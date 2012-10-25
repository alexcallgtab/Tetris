#include "base.h"


void	init_piece0(t_env* env)
{
	env->piece.x = 10;
	env->piece.x1 = 11;
	env->piece.x2 = 12;
	env->piece.x3 = 13;
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
	env->piece.x = 12;
	env->piece.x1 = 11;
	env->piece.x2 = 12;
	env->piece.x3 = 13;
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


void	init_piece6(t_env* env)
{
	env->piece.x = 12;
	env->piece.x1 = 13;
	env->piece.x2 = 12;
	env->piece.x3 = 13;
	env->piece.y = 7;
	env->piece.y1 = 7;
	env->piece.y2 = 8;
	env->piece.y3 = 8;
	env->piece.rot = 6;
}


void	init_piece5(t_env* env)
{
	env->piece.x = 12;
	env->piece.x1 = 14;
	env->piece.x2 = 13;
	env->piece.x3 = 13;
	env->piece.y = 7;
	env->piece.y1 = 8;
	env->piece.y2 = 8;
	env->piece.y3 = 7;
	env->piece.rot = 0;
	env->piece.rot1 = piece5_rot1;
	env->piece.rot2 = piece5_rot0;
}
