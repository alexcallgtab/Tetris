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
	init_cadre(env);
	generate_piece(env);
	return 0;
}

int	run(t_env* env)
{
	char c;
	struct sigaction act;

	act.sa_handler = resize_env;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	while	(1)
	{
		sigaction(SIGWINCH,&act,NULL);
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
	run(&env);
	return 0;
}
