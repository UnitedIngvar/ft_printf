char *ft_char_to_str(char c)
{
	char *str;

	str = malloc(sizeof(char) + 1);
	str[0] = c;
	str[1] = '\0';
	return str;
}
