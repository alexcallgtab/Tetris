#include "base.h"


void	init_piece0(t_env* env)
{
	env->piece.x = 5;
	env->piece.x1 = 6;
	env->piece.x2 = 7;
	env->piece.x3 = 7;
	env->piece.y = env->h - 19;
	env->piece.y1 = env->h - 19;
	env->piece.y2 = env->h - 19;
	env->piece.y3 = env->h - 19;
	env->piece.rot = 0;
	env->piece.rot1 = piece0_rot1;
	env->piece.rot2 = piece0_rot2;
}

void	init_piece1(t_env* env)
{
	env->piece.x = 5;
	env->piece.x1 = 4;
	env->piece.x2 = 5;
	env->piece.x3 = 6;
	env->piece.y = env->h - 18;
	env->piece.y1 = env->h - 19;
	env->piece.y2 = env->h - 19;
	env->piece.y3 = env->h - 19;
	env->piece.rot = 0;
	env->piece.rot1 = piece1_rot1;
	env->piece.rot2 = piece1_rot2;
	env->piece.rot3 = piece1_rot3;
	env->piece.rot4 = piece1_rot4;
}


void	init_piece6(t_env* env)
{
	env->piece.x = 5;
	env->piece.x1 = 6;
	env->piece.x2 = 5;
	env->piece.x3 = 6;
	env->piece.y = env->h - 19;
	env->piece.y1 = env->h - 19;
	env->piece.y2 = env->h - 18;
	env->piece.y3 = env->h - 18;
	env->piece.rot = 6;
}


void	init_piece5(t_env* env)
{
	env->piece.x = 5;
	env->piece.x1 = 7;
	env->piece.x2 = 6;
	env->piece.x3 = 6;
	env->piece.y = env->h - 19;
	env->piece.y1 = env->h - 18;
	env->piece.y2 = env->h - 18;
	env->piece.y3 = env->h - 19;
	env->piece.rot = 0;
	env->piece.rot1 = piece5_rot1;
	env->piece.rot2 = piece5_rot0;
}
