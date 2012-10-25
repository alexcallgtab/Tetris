#ifndef _base_h_
#define _base_h

typedef struct	s_wall
{
	int	x;
	int	y;
	struct s_wall	*next;
}	t_wall;

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
	void	(*rot1)(struct s_piece*);
	void	(*rot2)(struct s_piece*);
	void	(*rot3)(struct s_piece*);
	void	(*rot4)(struct s_piece*);
}	t_piece;


typedef struct	s_env
{
	int	w;
	int	h;
	char*	cm;
	char*	cl;
	int	piece_active;
	int	numb_wall;
	t_piece	piece;
	t_wall	wall;
}	t_env;

void	init_piece1(t_env* env);
void	init_piece0(t_env* env);
void	init_pieces(t_env* env);
char	check_touch(t_env* env);
int	id_put(int c);
int	init_env(t_env* env);
void	init_cadre(t_env* env);
void    resize_env(int i);
void	show_piece(t_env* env);
void	id_print_str(char* str);
void	rotation_piece(t_env* env);
void	erase_screen_piece(t_env* env);
void	piece0_rot1(struct s_piece*);
void	piece0_rot2(struct s_piece*);
void	piece1_rot1(struct s_piece*);
void	piece1_rot2(struct s_piece*);
void	piece1_rot3(struct s_piece*);
void	piece1_rot4(struct s_piece*);
void	piece5_rot1(struct s_piece*);
void	piece5_rot0(struct s_piece*);
void	action_touch(t_env* env, char c);
void	down_piece(t_env* env);
void	check_colli(t_env* env);
void	check_wall_full(t_env* env);
void	generate_piece(t_env* env);

#endif
