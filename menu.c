#include <term.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include "base.h"

void	display_menu_button(t_env* env, int w, int h)
{
	int	x;
	int	y;
	char	c;

	x = w /2 - 21;
	y = h /2;
	c = 0;
	tputs(tgoto(env->cm, x, y), 1, id_put);
	id_print_str("\033[01;40mAppuyer sur le barre d espace pour jouer...");
	while (c != 32)
		c = check_touch(env);
	env->status = 1;
}

void	display_menu(t_env* env, int w, int h)
{
	int x;
	int y;

	tputs(env->cl, 1, id_put);
	x = 0;
	while (x < w)
	{
		tputs(tgoto(env->cm, x, 0), 1, id_put);
		id_print_str("\033[01;41m ");
		tputs(tgoto(env->cm, x, h - 1), 1, id_put);
		id_print_str("\033[01;41m ");
		x = x + 1;
	}
	y = 0;
	while (y < h - 1)
	{
		tputs(tgoto(env->cm, 0, y), 1, id_put);
		id_print_str("\033[01;41m ");
		tputs(tgoto(env->cm, w, y), 1, id_put);
		id_print_str("\033[01;41m ");
		y = y + 1;
	}
	display_menu_button(env,w,h);
}

int	run_menu(t_env* env)
{
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	printf("%d %d\n",w.ws_col, w.ws_row);
	if (w.ws_col < 40 || w.ws_row < 20)
		return 1;
	display_menu(env,w.ws_col,w.ws_row);

	return 0;
}
