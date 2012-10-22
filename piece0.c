#include "base.h"



void	piece0_rot1(struct s_piece* piece)
{
	piece->x = piece->x2;
	piece->x1 = piece->x2;
	piece->x3 = piece->x2;
	piece->y = piece->y2 + 2;
	piece->y1 = piece->y2 + 1;
	piece->y3 = piece->y2 - 1;
	piece->rot = 1;
}

void	piece0_rot2(struct s_piece* piece)
{
	piece->x = piece->x2 - 2;
	piece->x1 = piece->x2 - 1;
	piece->x3 = piece->x2 + 1;
	piece->y = piece->y2;
	piece->y1 = piece->y2;
	piece->y3 = piece->y2;
	piece->rot = 0;
}
