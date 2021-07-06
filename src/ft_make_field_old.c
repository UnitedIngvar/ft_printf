static void ft_makestr_helper(t_opts *opts, const char *str, char *res, ssize_t strlen)
{
	ssize_t i;

	i = 0;
	if (opts->flag == '-')
		while (i < opts->width && str[i])
		{
			res[i] = str[i];
			i++;
		}
	else
	{
		while (strlen-- >= 0)
			res[--opts->width] = str[strlen];
	}
}

static void	ft_make_str(t_opts *opts, const char *str, char *res, \
		ssize_t strlen)
{
	ssize_t	i;

	i = 0;
	if (opts->precision >= 0)
	{
		if (opts->flag == '-')
			while (i < strlen && i < opts->precision && i < opts->width)
			{
				res[i] = str[i];
				i++;
			}
		else
		{
			if (strlen > opts->precision)
				strlen = opts->precision;
			while (i < strlen && i < opts->precision)
			{
				res[opts->width - strlen + i] = str[i];
				i++;
			}

		}
	}
	else
		ft_makestr_helper(opts, str, res, strlen);
}

static void	ft_place_spaces(t_opts *opts, const char *str, char *res, \
		ssize_t strlen)
{
	ssize_t	i;

	i = 0;
	while (i < opts->width)
		res[i++] = ' ';
	ft_make_str(opts, str, res, strlen);
}

char	*ft_make_field(t_opts *opts, const char *str)
{
	char	*res;
	ssize_t	strlen;

	strlen = ft_strlen(str);
	if (strlen > opts->width)
		opts->width = strlen;
	if (opts->type == 'c' || opts->type == 'i' || opts->type == 'd')
		if (opts->width )
	res = (char *)malloc(opts->width * sizeof(*res));
	printf("\n%lu strlen\n",strlen);
	if (!res)
		return (NULL);
	ft_place_spaces(opts, str, res, strlen);
	return (res);
}
