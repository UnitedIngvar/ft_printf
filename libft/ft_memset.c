#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*strs;

	strs = (char *)s;
	i = 0;
	while (i < n)
		strs[i++] = c;
	return (s);
}
