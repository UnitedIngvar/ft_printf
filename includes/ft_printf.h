#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
#include <stdio.h>
typedef struct s_opts
{
	char	flag;
	int		width;
	int		precision;
	char	type;
} t_opts;

void	ft_char_handler(char *c);
int		ft_printf(const char *format, ...);
void	ft_printstr(char *str);
void	ft_decToHex(unsigned int n, char *base, size_t *counter);
void	ft_printP(void *arg, char *base, size_t *counter);
char	*ft_uItoa(unsigned int n);
t_opts	*ft_parse_args(const char **args, va_list ap);
char	*ft_make_field(t_opts *opts, char *str, int *len);
void	ft_super_putchar(size_t *counter, const char *format);
int		ft_print_c(char c, t_opts *opts);

#endif
