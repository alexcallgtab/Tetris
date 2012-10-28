#include <term.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include "base.h"


int	id_put(int c)
{
	char	d;

	d = c;
	write(1, &d, 1);
	return 0;
}

int	init_env(t_env* env)
{
	struct termios tmp;
	char*	termtype = getenv("TERM");
	int	success;

	success = tgetent(0, termtype);
	if (success == 0)
		return 0;
	env->w = tgetnum("co");
	env->h = tgetnum("li");
	env->cm = tgetstr("cm", 0);
	env->cl = tgetstr("cl", 0);
	tputs(tgetstr("vi", 0), 1, id_put);
	tputs(tgetstr("bl", 0), 1, id_put);
	tcgetattr(0, &tmp);
	tmp.c_lflag = (tmp.c_lflag | ICANON) ^ ICANON;
	tmp.c_lflag = (tmp.c_lflag | ECHO) ^ ECHO;
	tmp.c_cflag |= CS8;
	tcsetattr(0, TCSANOW, &tmp);
	env->numb_wall = 0;
	env->down = 0;
	return 0;
}

void	init_cadre(t_env* env)
{
	int	x;
	int	y;

	tputs(env->cl, 1, id_put);
	x = 0;
	while (x <= 10)
	{
		tputs(tgoto(env->cm, x, env->h - 21), 1, id_put);
		id_print_str("\033[01;41m ");
		tputs(tgoto(env->cm, x, env->h), 1, id_put);
		id_print_str("\033[01;41m ");
		x = x + 1;
	}
	y = env->h - 20;
	while (y < env->h)
	{
		tputs(tgoto(env->cm, 0, y), 1, id_put);
		id_print_str("\033[01;41m ");
		tputs(tgoto(env->cm, 10, y), 1, id_put);
		id_print_str("\033[01;41m ");
		y = y + 1;
	}
}



void	resize_env(t_env* env)
{
	struct	winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	if (w.ws_col != env->w || w.ws_row != env->h)
		error_resize(env);
}

char	check_touch(t_env*	env)
{
	char c;
	fd_set fdread;
	struct timeval timeout;
	int	retselect;

	FD_ZERO(&fdread);
	FD_SET(0,&fdread);
	timeout.tv_sec = 0;
	timeout.tv_usec = 300000;
	retselect = select(1, &fdread, 0 , 0, &timeout);
	if (retselect)
		read(0, &c,1);
	else
		c = '0';
	if (env->down < 2 && env->status == 1)
		env->down = env->down + 1;
	else if (env->status == 1)
	{
		env->down = 0;
		down_piece(env);
	}
	return c;
}
