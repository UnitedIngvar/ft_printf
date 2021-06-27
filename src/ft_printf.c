#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"


//Не забудь, нужно счиать еще и символы
int	ft_printf(char *format, ...)
{
	va_list ap;
	t_dict **hashtable;
	va_start(ap, format);

	hashtable = ft_dict_setup();
	while (format)
	{
		if (*format == '%')
			ft_pars_args(format++, ap);
		//else
			//ft_putchar(*format);
	}
	va_end(ap);
	return (0);
}

int main(void)
{
	ft_printf("%0-*.10i", 5, 6);
}
