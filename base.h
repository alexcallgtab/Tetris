#ifndef _base_h_
#define _base_h


typedef struct	s_piece
{
	int	x;
	int	y;
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	x3;
	int	y3;
	int	rot;
	int	piece;
	void	(*rot1)(t_env *);
}	t_piece;


typedef struct	s_env
{
	int	w;
	int	h;
	char*	cm;
	char*	cl;
	int	piece_active;
	t_piece	piece;
}	t_env;

void	init_piece1(t_env* env);
void	init_piece0(t_env* env);
void	init_pieces(t_env* env);
char	check_touch(t_env* env);
int	id_put(int c);
int	init_env(t_env* env);
void	init_cadre(t_env* env);
void    resize_env(t_env* env);
void	show_piece(t_env* env);
void	id_print_str(char* str);
void	rotation_piece(t_env* env);
void	erase_screen_piece(t_env* env);
void	piece0_rot1(t_env* env);
void	piece0_rot0(t_env* env);
void	piece1_rot1(t_env* env);
void	piece1_rot2(t_env* env);
void	piece1_rot3(t_env* env);
void	piece1_rot4(t_env* env);

#endif
