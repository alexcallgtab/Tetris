#include <term.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"


void	generate_piece(t_env* env)
{
	int	numb;

	srand(time(0));
	numb = (rand() % 6);
	if (numb == 0 || numb == 2 || numb == 4)
		init_piece0(env);
	else if (numb == 6)
		init_piece6(env);
	else if (numb == 5)
		init_piece5(env);
	else
		init_piece1(env);
	env->piece_active = 1;
}

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
	tputs(tgetstr("bl", 0), 1, id_put);
}

void	down_piece(t_env* env)
{
	erase_screen_piece(env);
	env->piece.y = env->piece.y + 1;
	env->piece.y1 = env->piece.y1 + 1;
	env->piece.y2 = env->piece.y2 + 1;
	env->piece.y3 = env->piece.y3 + 1;
}
