#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (!dst)
		return (ft_strlen(src));
	while (i < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
	{
		if (dstsize == i)
			dst[i - 1] = '\0';
		else
			dst[i] = '\0';
	}
	return (ft_strlen(src));
}
