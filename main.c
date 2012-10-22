#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <term.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <termios.h>
#include "base.h"


int	init(t_env* env)
{
	if (init_env(env))
		return (1);
	init_cadre(env);
	return 0;
}

int	run(t_env* env)
{
	char c;

	while	(1)
	{
		c = check_touch(env);
		if (c == 'd')
			rotation_piece(env);
		show_piece(env);
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
