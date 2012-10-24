#include "base.h"
#include <stdlib.h>
#include <unistd.h>

int	piece_wall(t_env* env, t_wall *walls)
{
	if (env->piece.x == walls->x && env->piece.y + 1 == walls->y)
		return 1;
	if (env->piece.x1 == walls->x && env->piece.y1 + 1 == walls->y)
		return 1;
	if (env->piece.x2 == walls->x && env->piece.y2 + 1 == walls->y)
		return 1;
	if (env->piece.x3 == walls->x && env->piece.y3 + 1 == walls->y)
		return 1;
	return 0;
}

void	save_piece_wall(t_env* env)
{
	t_wall	*walls;

	walls = &env->wall;
	if (env->numb_wall > 0)
	{
		while (walls->next != 0)
			walls = walls->next;
		walls->next = (t_wall*)malloc(sizeof(*walls));
		walls = walls->next;
	}
	walls->x = env->piece.x;
	walls->y = env->piece.y;
	walls->next = (t_wall*)malloc(sizeof(*walls));
	walls = walls->next;
	walls->x = env->piece.x1;
	walls->y = env->piece.y1;
	walls->next = (t_wall*)malloc(sizeof(*walls));
	walls = walls->next;
	walls->x = env->piece.x2;
	walls->y = env->piece.y2;
	walls->next = (t_wall*)malloc(sizeof(*walls));
	walls = walls->next;
	walls->x = env->piece.x3;
	walls->y = env->piece.y3;
	walls->next = 0;
	env->numb_wall = env->numb_wall + 1;
	init_piece1(env);

}

void	check_colli(t_env* env)
{
	t_wall	*walls;

	walls = &env->wall;
	if (env->piece.y == env->h -1 || env->piece.y1 == env->h -1 || env->piece.y2 == env->h -1 ||
	    env->piece.y3 == env->h -1)
		save_piece_wall(env);
	else
	{
		if (env->numb_wall > 0)
		while (walls != 0)
		{
			if (piece_wall(env, walls))
				save_piece_wall(env);
			walls = walls->next;
		}
	}
}
