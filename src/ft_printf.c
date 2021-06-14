#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/utils.h"

int	ft_printf(char *format, ...)
{
	va_list ap;
	t_dict **hashtable;

	hashtable = ft_dict_setup();
	(hashtable['c']->func_defn)("c");
	va_start(ap, format);
	va_end(ap);
	return (0);
}

int main(void)
{
	ft_printf("str;", 5, 6, 7);
}
