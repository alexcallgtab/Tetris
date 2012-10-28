#include "base.h"


void	move_right(t_env* env)
{
	erase_screen_piece(env);
	env->piece.x = env->piece.x + 1;
	env->piece.x1 = env->piece.x1 + 1;
	env->piece.x2 = env->piece.x2 + 1;
	env->piece.x3 = env->piece.x3 + 1;
}

void	move_left(t_env* env)
{
	erase_screen_piece(env);
	env->piece.x = env->piece.x - 1;
	env->piece.x1 = env->piece.x1 - 1;
	env->piece.x2 = env->piece.x2 - 1;
	env->piece.x3 = env->piece.x3 - 1;
}

void	move_down(t_env* env)
{
	erase_screen_piece(env);
	env->piece.y = env->piece.y + 1;
	env->piece.y1 = env->piece.y1 + 1;
	env->piece.y2 = env->piece.y2 + 1;
	env->piece.y3 = env->piece.y3 + 1;
}



void	action_touch(t_env* env, char c)
{
	if (c == 'd' && env->piece.x < 10 - 1 && env->piece.x1 < 10 - 1 && env->piece.x2 < 10 - 1 && env->piece.x3 < 10 - 1)
		move_right(env);
	if (c == 'a' && env->piece.x > 1 && env->piece.x1 > 1 && env->piece.x2 > 1 && env->piece.x3 > 1)
		move_left(env);
	if (c == 'w')
		rotation_piece(env);
	if (c == 's')
		move_down(env);
}
