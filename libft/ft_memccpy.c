#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*strdest;
	unsigned char	*strsrc;

	strdest = (unsigned char *)dest;
	strsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		strdest[i] = strsrc[i];
		if (strdest[i] == (unsigned char)c)
			return (strdest + (i + 1));
		i++;
	}
	return (NULL);
}
