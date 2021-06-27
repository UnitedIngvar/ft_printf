char	*ft_make_space(t_opts *opts)
{
	char	*str;
	int		i;

	if (opts->width > opts->precision)
		str = (char *)malloc(opts->width * sizeof(*str));
	else
		str = (char *)malloc(opts->precision * sizeof(*str));
	if (!str)
		return (NULL);
	i = 0;
	while (i < (opts->width * sizeof(*str)))
		str[i++] = ' ';
	return (str);
}
