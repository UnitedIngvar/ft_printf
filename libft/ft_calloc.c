/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:13:54 by ftassada          #+#    #+#             */
/*   Updated: 2021/04/22 20:06:21 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
