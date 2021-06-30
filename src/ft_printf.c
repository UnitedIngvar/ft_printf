static int	ft_xsX(t_opts *opts, va_list ap, size_t *counter)
{
	char	*strnum;

	if (opts->type == 'x' || opts->type == 'X')
	{
		if (opts->type == 'x')
			ft_decToHex(va_arg(ap, unsigned int), "0123456789abcdef", counter);
		else if (opts->type == 'X')
			ft_decToHex(va_arg(ap, unsigned int), "0123456789ABCDEF", counter);
		return (1);
	}
	else if (opts->type == 's')
	{
		strnum = ft_make_space(opts, va_arg(ap, char *));
		*counter += ft_strlen(strnum);
		ft_printstr(strnum);
		free(strnum);
		return (1);
	}
	return (0);
}

static int	ft_up(t_opts *opts, va_list ap, size_t *counter)
{
	char	*strnum;

	if (opts->type == 'u')
	{
		strnum = ft_uItoa(va_arg(ap, unsigned int));
		*counter += ft_strlen(strnum);
		ft_printstr(strnum);
		free(strnum);
		return (1);
	}
	else if (opts->type == 'p')
	{
		(ft_printP(va_arg(ap, void *), "0123456789abcdef", counter));
		return (1);
	}
	return (0);
}

static int	ft_cdi(t_opts *opts, va_list ap, size_t *counter)
{
	char	*strnum;

	if (opts->type == 'c')
	{
		*counter += 1;
		ft_putchar_fd(va_arg(ap, int), 1);
		return (1);
	}
	else if (opts->type == 'd' || opts->type == 'i')
	{
		strnum = ft_itoa(va_arg(ap, int));
		*counter += ft_strlen(strnum);
		ft_printstr(strnum);
		free(strnum);
		return (1);
	}
	return (0);
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
			if (!ft_xsX(opts, ap, &counter) && !ft_up(opts, ap, &counter) \
					&& !ft_cdi(opts, ap, &counter))
			free(opts);
		}
		else
			ft_super_putchar(&counter, format);
	}
	va_end(ap);
	return (counter);
}
