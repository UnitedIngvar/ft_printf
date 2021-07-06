int	ft_print_c(char c, t_opts *opts)
{
	char	*res;
	int		len;

	len = 0;
	res = ft_make_field(opts, ft_char_to_str(c), &len);
	if (opts->flag == '-')
		res[len - 1] = c;
	else
		res[0] = c;
	ft_putstr(res);
	return (len);
}
