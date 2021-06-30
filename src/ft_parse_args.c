static char	ft_parse_flag(const char **args)
{
	char	flag;

	flag = '\0';
	if (**args == '0')
	{
		flag = '0';
		while (**args == '0')
			(*args)++;
	}
	if (**args == '-')
	{
		flag = '-';
		while (**args == '-')
			(*args)++;
	}
	while (**args == '-' || **args == '0')
		(*args)++;
	return (flag);
}

static int	ft_parse_width(const char **args, va_list ap)
{
	int	width;

	width = 0;
	if (**args == '*')
		width = va_arg(ap, int);
	else if (ft_isdigit(**args))
		width = ft_atoi(*args);
	while (ft_isdigit(**args) || **args == '*')
		(*args)++;
	return (width);
}

static int	ft_parse_precision(const char **args, va_list ap)
{
	int	prec;

	prec = -1;
	if (**args == '.')
		(*args)++;
	else
		return (prec);
	if (**args == '*')
		prec = va_arg(ap, int);
	else if (ft_isdigit(**args))
		prec = ft_atoi(*args);
	while (ft_isdigit(**args) || **args == '*')
		(*args)++;
	return (prec);
}

t_opts	*ft_parse_args(const char **args, va_list ap)
{
	t_opts	*opts;

	opts = (t_opts*)malloc(sizeof(t_opts));
	if (!opts)
		return (NULL);
	opts->flag = ft_parse_flag(args);
	opts->width = ft_parse_width(args, ap);
	if (opts->width < 0)
	{
		opts->width = -opts->width;
		opts->flag = '-';
	}
	opts->precision = ft_parse_precision(args, ap);
	opts->type = **args;
	return (opts);
}
