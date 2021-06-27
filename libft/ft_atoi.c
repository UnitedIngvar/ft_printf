	if (digits > 19 || (digits == 19 && res < 0))
	{
		if (flag == 1)
			return (-1);
		return (0);
	}
	return ((int)res * flag);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	ssize_t	res;
	int		flag;
	int		digits;

	digits = 0;
	i = 0;
	res = 0;
	flag = 1;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		flag *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + ((char)str[i] - '0');
		i++;
		digits++;
	}
	return (ft_check_overflow(res, digits, flag));
}
