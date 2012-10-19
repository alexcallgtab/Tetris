#include "base.h"
#include <stdlib.h>

void	init_pieces(t_env* env)
{
	init_piece0(env);
	init_piece1(env);
	/*init_piece2(env);
	init_piece3(env);
	init_piece4(env);
	init_piece5(env);
	init_piece6(env);*/
}


void	show_piece(t_env* env)
{
	tputs(tgoto(env->cm, env->pieces.piece1.x, env->pieces.piece1.y), 1, id_put);
	id_print_str("\033[01;46m#");
	tputs(tgoto(env->cm, env->pieces.piece1.x1, env->pieces.piece1.y1), 1, id_put);
	id_print_str("\033[01;46m#");
	tputs(tgoto(env->cm, env->pieces.piece1.x2, env->pieces.piece1.y2), 1, id_put);
	id_print_str("\033[01;46m#");
	tputs(tgoto(env->cm, env->pieces.piece1.x3, env->pieces.piece1.y3), 1, id_put);
	id_print_str("\033[01;46m#");
}

void	erase_screen_piece(t_env* env)
{
	tputs(tgoto(env->cm, env->pieces.piece1.x, env->pieces.piece1.y), 1, id_put);
	id_print_str("\033[01;40m ");
	tputs(tgoto(env->cm, env->pieces.piece1.x1, env->pieces.piece1.y1), 1, id_put);
	id_print_str("\033[01;40m ");
	tputs(tgoto(env->cm, env->pieces.piece1.x2, env->pieces.piece1.y2), 1, id_put);
	id_print_str("\033[01;40m ");
	tputs(tgoto(env->cm, env->pieces.piece1.x3, env->pieces.piece1.y3), 1, id_put);
	id_print_str("\033[01;40m ");
}

void	rotation_piece(t_env* env)
{
	erase_screen_piece(env);
	if (env->pieces.piece1.rot == 0)
		piece1_rot1(env);
	else if (env->pieces.piece1.rot == 1)
		piece1_rot2(env);
	else if (env->pieces.piece1.rot == 2)
		piece1_rot3(env);
	else if (env->pieces.piece1.rot == 3)
		piece1_rot4(env);
}
