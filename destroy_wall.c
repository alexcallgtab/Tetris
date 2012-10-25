#include "base.h"


void	clear_wall(t_env* env, int y)
{
	t_wall	*walls;

	walls = &env->wall;
	while (walls != 0)
	{
		if (walls->y == y)
		{
			tputs(tgoto(env->cm, walls->x, walls->y), 1, id_put);
			id_print_str("\033[01;40m ");
			walls->y = 0;
			walls->x = 0;
		}
		walls = walls->next;
	}
	walls = &env->wall;
	while (walls != 0)
	{
		if (walls->y < y && walls->y != 0)
		{
			tputs(tgoto(env->cm, walls->x, walls->y), 1, id_put);
			id_print_str("\033[01;40m ");
			walls->y = walls->y + 1;
			tputs(tgoto(env->cm, walls->x, walls->y), 1, id_put);
			id_print_str("\033[01;46m#");
		}
		walls = walls->next;
	}
}

int	check_wall_x(t_env *env, int y)
{
	int	x;
	int	status;
	t_wall	*walls;

	status = 0;
	x = 1;
	while (x != env->w - 1)
	{
		status = 0;
		walls = &env->wall;
		while (walls != 0)
		{
			if (walls->x == x && walls->y == y)
			{
				status = 1;
				break;
			}
			walls = walls->next;
		}
		if (status == 0)
			return 0;
		x = x + 1;
	}
	return 1;
}

void	check_wall_full(t_env* env)
{
	int	y;
	t_wall	*walls;

	y = env->h;
	while (y != 0)
	{
		if (check_wall_x(env, y))
			clear_wall(env,y);
		y = y - 1;
		
	}
}
