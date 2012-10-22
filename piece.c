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

	
}
