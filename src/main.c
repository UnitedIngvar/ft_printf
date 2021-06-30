#include <stdio.h>
#include <unistd.h>
#include "../includes/ft_printf.h"
#include "ft_printf.c"
int main(void)
{
	int i = ft_printf("%s","0");
	printf("\ni = %i",i);
	return (0);
}
