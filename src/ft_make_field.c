static void	ft_place_spaces(t_opts *opts, char *str)
{
	ssize_t	i;

	i = 0;
	while (i < opts->width)
		str[i++] = ' ';
}

//function to allocate space for and return
//a pointer to the resulting string and the length of it
char	*ft_make_field(t_opts *opts, char *str, int *len)
{
	char	*res;
	ssize_t	strlen;

	strlen = ft_strlen(str);
	if (strlen > opts->width)
		opts->width = strlen;
	res = (char *)malloc((opts->width + 1) * sizeof(*res));
	res[opts->width] = '\0';
	if (!res)
		return (NULL);
	*len = ft_strlen(res);
	ft_place_spaces(opts, str);
	return (res);
}
