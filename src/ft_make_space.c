static void	ft_place_spaces(t_opts *opts, char *str, char *res)
{
	size_t	i;
	size_t	strlen;

	strlen = ft_strlen(str);
	i = 0;
	if (ft_strlen(str) <= opts->precision || opts->precision < 0)
		while (i < strlen)
		   res[i++] = ' ';
	else
		while (i < opts->precision)
			res[i++] = ' ';

}

static void ft_makestr_helper(t_opts *opts, char *str, char *res)
{
	ssize_t	i, j;

	i = -1;
	if (opts->flag == '-')
		while (++i < opts->precision)
			res[i] = str[i];
	else
	{
		i = opts->precision;
		j = opts->width;
		res[(j - 1)--] = str[(i - 1)--];
	}
}
static void	ft_make_str(t_opts *opts, char *str, char *res)
{
	ssize_t	i;
	size_t	strlen;

	strlen = ft_strlen(str);
	i = -1;
	if (ft_strlen(str) <= opts->precision || opts->precision < 0)
	{
		if (opts->flag == '-')
			while (++i < strlen)
				res[i] = str[i];
		else
			while (--(strlen + 1) != 0)
				res[strlen - 1] = str[strlen - 1];
	}
	else
		ft_makestr_helper(opts, str, res);
}

char	*ft_make_field(t_opts *opts, const char *str)
{
	char	*res;
	int		i;

	if (ft_strlen(str) <= opts->precision || opts->precision < 0)
		res = (char *)malloc(ft_strlen(str) * sizeof(*res));
	else
		res = (char *)malloc(opts->precision * sizeof(*res));
	if (!res)
		return (NULL);
	i = 0;
	ft_place_spaces(opts, str, res);

	ft_strlcpy(res, str, opts->width * sizeof(*res));
	return (res);
}

