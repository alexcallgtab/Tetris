#ifndef _base_h_
#define _base_h

typedef struct	s_env
{
	int	w;
	int	h;
	char*	cm;
	char*	cl;
}	t_env;

int	id_put(int c);
int	init_env(t_env* env);
void	init_cadre(t_env* env);
void    resize_env(t_env* env);


#endif
