#include "../includes/ft_printf.h"

void	ft_printstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &(str[i]), 1);
		i++;
	}
}

void	ft_decToHex(unsigned int n, char *base, size_t	*counter)
{
	unsigned int	i;

	if (n >= 16)
	{
		i = n % 16;
		n = n / 16;
		ft_decToHex(n, base, counter);
		write(1, base + i, 1);
		*counter += 1;
	}
	else if (n >= 0 && n < 16)
	{
		i = n % 16;
		write(1, base + i, 1);
		*counter += 1;
	}
}

void	ft_printP(void *arg, char *base, size_t *counter)
{
	size_t	i;
	size_t	sarg;

	sarg = (size_t)arg;
	if (sarg >= 16)
	{
		i = sarg % 16;
		sarg = sarg / 16;
		ft_printP((void *)sarg, base, counter);
		write(1, base + i, 1);
		*counter += 1;
	}
	else if (sarg >= 0 && sarg < 16)
	{
		i = sarg % 16;
		write(1, "0x", 2);
		write(1, base + i, 1);
		*counter += 3;
	}
}

void	ft_super_putchar(size_t *counter, const char *format)
{
	write(1, format, 1);
	*counter += 1;
	format++;
}
