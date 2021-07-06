static char *ft_char_to_str(char c)
{
	char *str;

	str = malloc(sizeof(char) + 1);
	str[0] = c;
	str[1] = '\0';
	return str;
}

int	ft_print_c(char c, t_opts *opts)
{
	char	*res;
	int		len;

	len = 0;
	res = ft_make_field(opts, ft_char_to_str(c), &len);
	printf("qwe %i", len);
	if (opts->flag == '-')
		res[len - 1] = c;
	else
		res[0] = c;
	ft_printstr(res);
	return (len);
}
