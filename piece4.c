 #include "base.h"

void	piece4_rot1(t_env* env)
{
	env->piece.x = env->pieces.piece5.x2;
	env->piece.x1 = env->pieces.piece5.x2 + 1;
	env->piece.x3 = env->pieces.piece5.x2 + 1;
	env->piece.y = env->pieces.piece5.y2 + 1;
	env->piece.y1 = env->pieces.piece5.y2;
	env->piece.y3 = env->pieces.piece5.y2 - 1;
	env->piece.rot = 1;
}

void	piece4_rot0(t_env* env)
{
	env->piece.x = env->pieces.piece5.x2 - 1;
	env->piece.x1 = env->pieces.piece5.x2;
	env->piece.x3 = env->pieces.piece5.x2 + 1;
	env->piece.y = env->pieces.piece5.y2;
	env->piece.y1 = env->pieces.piece5.y2 - 1;
	env->piece.y3 = env->pieces.piece5.y2 - 1;
	env->piece.rot = 0;
}
