#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <term.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <termios.h>
#include <signal.h>
#include "base.h"


int	init(t_env* env)
{
	if (init_env(env))
		return (1);
	env->status = 0;
	return 0;
}

int	run(t_env* env)
{
	char c;

	init_cadre(env);
	generate_piece(env);
	while	(1)
	{
		resize_env(env);
		if (env->piece_active == 0)
			generate_piece(env);
		c = check_touch(env);
		action_touch(env,c);
		show_piece(env);
		check_colli(env);
		if (env->numb_wall > 0)
			check_wall_full(env);
	}
	return 0;
}

int	main(void)
{
	t_env	env;

	init(&env);
	if(run_menu(&env))
		erreur_menu(&env);
	run(&env);
	return 0;
}

void	restart_level(t_env* env)
{
	t_wall	*walls;
	t_wall	*tmp;

	walls = &env->wall;
	while (walls->next != 0)
	{
		tmp = walls->next;
		walls = tmp->next;
		if (tmp->next == 0)
			break;
		free(tmp->next);
	}
	free(env->wall.next);
	sleep(5);
	init(env);
	if(run_menu(env))
		erreur_menu(env);
	run(env);
}
