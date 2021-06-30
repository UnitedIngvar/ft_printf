#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*strdest;
	unsigned char	*strsrc;

	strdest = (unsigned char *)dest;
	strsrc = (unsigned char *)src;
	if (strdest == NULL && strsrc == NULL)
		return (NULL);
	if ((strdest > strsrc) && (strdest < strsrc + n))
	{
		strdest += n;
		strsrc += n;
		while (n--)
			*--strdest = *--strsrc;
	}
	else
		while (n--)
			*strdest++ = *strsrc++;
	return (dest);
}
