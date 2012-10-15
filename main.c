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
	
	struct termios tmp;
	tcgetattr(0, &tmp);
	tmp.c_lflag = (tmp.c_lflag | ICANON) ^ ICANON;
	tmp.c_lflag = (tmp.c_lflag | ECHO) ^ ECHO;
	tcsetattr(0, TCSANOW, &tmp);
	if (init_env(env))
		return (1);
	init_cadre(env);
	return 0;
}

int	run(t_env* env)
{
	char	c;
	fd_set	fdread;
	struct timeval	timeout;

	FD_ZERO(&fdread);
	FD_SET(0,&fdread);

	timeout.tv_sec = 5;
	timeout.tv_usec = 0;
	
	while (select(1, &fdread, 0 , 0, &timeout) >= 0)
	{
		read(0, &c,1);
		write(1,"A",1);
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
