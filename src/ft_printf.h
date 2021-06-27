#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
void	ft_char_handler(char *c);

typedef struct s_opts
{
	char	flag;
	int		width;
	int		precision;
	char	type;
	void	*value;
} t_opts;

#endif
