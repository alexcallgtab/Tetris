#include "base.h"


void	init_piece0(t_env* env)
{
	env->pieces.piece0.x = 20;
	env->pieces.piece0.x1 = 21;
	env->pieces.piece0.x2 = 22;
	env->pieces.piece0.x3 = 23;
	env->pieces.piece0.y = 7;
	env->pieces.piece0.y1 = 7;
	env->pieces.piece0.y2 = 7;
	env->pieces.piece0.y3 = 7;
	env->pieces.piece0.rot = 0;
}

void	init_piece1(t_env* env)
{
	env->pieces.piece1.x = 22;
	env->pieces.piece1.x1 = 21;
	env->pieces.piece1.x2 = 22;
	env->pieces.piece1.x3 = 23;
	env->pieces.piece1.y = 8;
	env->pieces.piece1.y1 = 7;
	env->pieces.piece1.y2 = 7;
	env->pieces.piece1.y3 = 7;
	env->pieces.piece1.rot = 0;
}
