#include "ft_printf.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

//если он видит лишний аргумент, он пишет все оставшееся текстом ->
//printf("str: %-0**i\n"); ->
//out: *i
//должен оставнавливать указатель там, где произошло говно какое-то
static void* ft_parse_value(char type, va_list ap, void **o_value)
{
	if (type == 'i' || type == 'd')
		memset(o_value, va_arg(ap, int), sizeof(int));
	else if (type == 'u' || type == 'x')
		memset(o_value, va_arg(ap, unsigned int), sizeof(unsigned int));
	else if (type == 's')
		memset(o_value, va_arg(ap, int), sizeof(char *));
	else if (type == 'c')
		memset(o_value, va_arg(ap, int), sizeof(char));
	else if (type == 'p')
		memset(o_value, va_arg(ap, int), sizeof(void *));
}

static char ft_parse_flag(char **args)
{
	char	flag;

	flag = '\0';
	while (isspace(**args))
		*args++;
	if (**args == '0')
	{
		flag = '0';
		while (**args == '0')
			*args++;
	}
	while (isspace(**args))
		*args++;
	if (**args == '-')
	{
		flag = '-';
		while (**args == '-')
			*args++;
	}
	while (**args == '-' || **args == '0' || isspace(**args))
		*args++;
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
		*args++;
	return (width);
}

static int	ft_parse_precision(char **args, va_list ap)
{
	int	prec;

	prec = 0;
	if (**args == '.')
		*args++;
	else
		return (0);
	if (**args == '*')
		prec = va_arg(ap, int);
	else if (isdigit(**args))
		prec = atoi(*args);
	while (isdigit(**args) || **args == '*')
		*args++;
	return (prec);
}

t_opts	*ft_parse_args(char **args, va_list ap)
{
	t_opts	*opts;
	char	opt;
	int		argc;

	//тут придется перелопатить все, чтобы функция принимала
	//поинтер на часть структуры, а возвращала 0 или -1
	argc = 0;
	opts->flag = ft_parse_flag(args);
	opts->width = ft_parse_width(args, ap);
	if (opts->width < 0)
		opts->flag = '-';
	opts->precision = ft_parse_precision(args, ap);
	if (isalpha(**args))
		opts->type = **args; //ptr -> type
	ft_parse_value(opts->type, ap, &(opts->value));
	return (opts);
}
