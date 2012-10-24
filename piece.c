#include "base.h"
#include <stdlib.h>


void	show_piece(t_env* env)
{
	tputs(tgoto(env->cm, env->piece.x, env->piece.y), 1, id_put);
	id_print_str("\033[01;46m#");
	tputs(tgoto(env->cm, env->piece.x1, env->piece.y1), 1, id_put);
	id_print_str("\033[01;46m#");
	tputs(tgoto(env->cm, env->piece.x2, env->piece.y2), 1, id_put);
	id_print_str("\033[01;46m#");
	tputs(tgoto(env->cm, env->piece.x3, env->piece.y3), 1, id_put);
	id_print_str("\033[01;46m#");
}

void	erase_screen_piece(t_env* env)
{
	tputs(tgoto(env->cm, env->piece.x, env->piece.y), 1, id_put);
	id_print_str("\033[01;40m ");
	tputs(tgoto(env->cm, env->piece.x1, env->piece.y1), 1, id_put);
	id_print_str("\033[01;40m ");
	tputs(tgoto(env->cm, env->piece.x2, env->piece.y2), 1, id_put);
	id_print_str("\033[01;40m ");
	tputs(tgoto(env->cm, env->piece.x3, env->piece.y3), 1, id_put);
	id_print_str("\033[01;40m ");
}

void	rotation_piece(t_env* env)
{
	erase_screen_piece(env);
	if (env->piece.rot == 0)
		env->piece.rot1(&env->piece);
	else if (env->piece.rot == 1)
		env->piece.rot2(&env->piece);
	else if (env->piece.rot == 2)
		env->piece.rot3(&env->piece);
	else if (env->piece.rot == 3)
		env->piece.rot4(&env->piece);
	
	
}

void	down_piece(t_env* env)
{
	erase_screen_piece(env);
	env->piece.y = env->piece.y + 1;
	env->piece.y1 = env->piece.y1 + 1;
	env->piece.y2 = env->piece.y2 + 1;
	env->piece.y3 = env->piece.y3 + 1;
}
