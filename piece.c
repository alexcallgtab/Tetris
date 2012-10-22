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
		piece1_rot1(env);
	else if (env->pieces.piece1.rot == 1)
		piece1_rot2(env);
	else if (env->pieces.piece1.rot == 2)
		piece1_rot3(env);
	else if (env->pieces.piece1.rot == 3)
		piece1_rot4(env);
}
