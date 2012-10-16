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
	tcgetattr(0, &tmp);
	tmp.c_lflag = (tmp.c_lflag | ICANON) ^ ICANON;
	tmp.c_lflag = (tmp.c_lflag | ECHO) ^ ECHO;
	tcsetattr(0, TCSANOW, &tmp);
	
	return 0;
}

void	init_cadre(t_env* env)
{
	int	x;
	int	y;

	tputs(env->cl, 1, id_put);
	x = 0;
	while (x < env->w)
	{
		tputs(tgoto(env->cm, x, 4), 1, id_put);
		write(1, ".", 1);
		tputs(tgoto(env->cm, x, env->h - 1), 1, id_put);
		write(1, ".", 1);
		x = x + 1;
	}
	y = 5;
	while (y < env->h - 1)
	{
		tputs(tgoto(env->cm, 0, y), 1, id_put);
		write(1, "#", 1);
		tputs(tgoto(env->cm, env->w, y), 1, id_put);
		write(1, "#", 1);
		y = y + 1;
	}
}



void	resize_env(t_env* env)
{
	struct	winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	if (env->w != w.ws_col || env->h != w.ws_row)
	{
	env->w = w.ws_col;
	env->h = w.ws_row;
	init_cadre(env);;
	}
}

char	check_touch(t_env*	env)
{
	char c;
	fd_set fdread;
	struct timeval timeout;
	int	retselect;

	FD_ZERO(&fdread);
	FD_SET(0,&fdread);

	timeout.tv_sec = 2;
	timeout.tv_usec = 0;

	retselect = select(1, &fdread, 0 , 0, &timeout);
	if (retselect)
	{
		read(0, &c,1);
		tputs(tgoto(env->cm, 0, 0), 1, id_put);
		id_print_str("               ");
		id_print_str("TOUCHE DETECTER");
		write(1, &c,1);
	}
	else
	{
		c = '0';
		tputs(tgoto(env->cm, 0, 0), 1, id_put);
		id_print_str("               ");
		id_print_str("NON  DETECTER");
	}
		
	return c;
}
