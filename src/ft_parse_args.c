//если он видит лишний аргумент, он пишет все оставшееся текстом ->
//printf("str: %-0**i\n"); ->
//out: *i
//должен оставнавливать указатель там, где произошло говно какое-то

static char ft_parse_flag(char **args)
{
	char	flag;

	flag = '\0';
	while (ft_isspace(**args))
		(*args)++;
	if (**args == '0')
	{
		flag = '0';
		while (**args == '0')
			(*args)++;
	}
	while (ft_isspace(**args))
		(*args)++;
	if (**args == '-')
	{
		flag = '-';
		while (**args == '-')
			(*args)++;
	}
	while (**args == '-' || **args == '0' || isspace(**args))
		(*args)++;
	return (flag);
}

static int ft_parse_width(char **args, va_list ap)
{
	int	width;

	width = 0;
	if (**args == '*')
		width = va_arg(ap, int);
	else if (isdigit(**args))
		width = atoi(*args);
	while (isdigit(**args) || **args == '*')
		(*args)++;
	return (width);
}

static int	ft_parse_precision(char **args, va_list ap)
{
	int	prec;

	prec = 0;
	if (**args == '.')
		(*args)++;
	else
		return (0);
	if (**args == '*')
		prec = va_arg(ap, int);
	else if (isdigit(**args))
		prec = atoi(*args);
	while (isdigit(**args) || **args == '*')
		(*args)++;
	return (prec);
}

t_opts	*ft_parse_args(const char **args, va_list ap)
{
	t_opts	*opts;
	char	opt;
	int		argc;

	//тут придется перелопатить все, чтобы функция принимала
	//поинтер на часть структуры, а возвращала 0 или -1
	argc = 0;
	opts = (t_opts*)malloc(sizeof(t_opts));
	opts->flag = ft_parse_flag(args);
	opts->width = ft_parse_width(args, ap);
	if (opts->width < 0)
		opts->flag = '-';
	opts->precision = ft_parse_precision(args, ap);
	opts->type = **args; //ptr -> type
	return (opts);
}
