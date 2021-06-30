#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;
	size_t	i;	

	res = (char *)malloc(size * nmemb);
	i = 0;
	if (!res)
		return (NULL);
	while (i < (size * nmemb))
		res[i++] = '\0';
	return (res);
}
