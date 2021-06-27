static int	ft_xpuX(t_opts *opts, va_list ap, size_t *counter)
{
	char			*strnum;

	if (opts->type == '%')
		write(1, "%", 1);
	else if (opts->type == 'x' || opts->type == 'X')
	{
		if (opts->type == 'x')
			ft_decToHex(va_arg(ap, unsigned int), "0123456789abcdef", counter);
		else if (opts->type == 'X')
			ft_decToHex(va_arg(ap, unsigned int), "0123456789ABCDEF", counter);
	}
	else if (opts->type == 'p')
		ft_printP(va_arg(ap, void *), "0123456789abcdef", counter);
	else if (opts->type == 'u')
	{
		strnum = ft_uItoa(va_arg(ap, unsigned int));
		*counter += ft_strlen(strnum);
		ft_printstr(strnum);
		free(strnum);
	}
}

static void	ft_csdi(t_opts *opts, va_list ap, size_t *counter)
{
	char	*strnum;

	if (opts->type == 's')
	{
		strnum = va_arg(ap, char *);
		*counter += ft_strlen(strnum);
		ft_printstr(strnum);
	}
	else if (opts->type == 'c')
	{
		*counter += 1;
		ft_putchar_fd(va_arg(ap, int), 1);
	}
	else if (opts->type == 'd' || opts->type == 'i')
	{
		strnum = ft_itoa(va_arg(ap, int));
		*counter += ft_strlen(strnum);
		ft_printstr(strnum);
		free(strnum);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	counter;
	t_opts	*opts;

	counter = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			opts = ft_parse_args(&format, ap);
			ft_xpuX(opts, ap, &counter);
			ft_csdi(opts, ap, &counter);
			free(opts);
		}
		else
		{
			write(1, format, 1);
			counter++;
		}
		format++;
	}
	va_end(ap);
	return (counter);
}
