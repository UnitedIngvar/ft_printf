#include "ft_printf.h"

void	ft_char_handler(char *c)
{
	write(1, c, 1);
}
