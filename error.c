#include <term.h>
#include <unistd.h>
#include "base.h"


void	erreur_menu(t_env* env)
{
	id_print_str("\033[00;40m");
	tputs(env->cl, 1, id_put);
	id_print_str("error MENY");
	sleep(10);
}

void	error_size(t_env* env)
{
	id_print_str("\033[00;40m");
	tputs(env->cl, 1, id_put);
	id_print_str("PROBLEME d affichage");
}

void	error_resize(t_env* env)
{
	id_print_str("\033[00;40m");
	tputs(env->cl, 1, id_put);
	id_print_str("Desoler mais cet application ne gere pas les resize\n");
	id_print_str("Appuyer sur la barre d espace pour relancer une partie\n");
	restart_level(env);
}
