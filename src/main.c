#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int i = ft_printf("%c*", 0);
	printf("\ni = %i",i);
	return (0);
}
