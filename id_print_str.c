int	write(int handle, void *buffer, int nbyte);

void	id_print_str(char* str)
{
	int num_pos;

	num_pos = 0;
	while ( str[num_pos] != '\0')
	{
		write(1,str + num_pos,1);
		num_pos = num_pos + 1;
	}
}
