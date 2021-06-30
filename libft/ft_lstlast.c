#include "libft.h"

t_list	*ft_lstlast(t_list	*lst)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		if (temp->next == NULL)
			return (temp);
		temp = temp->next;
	}
	return (temp);
}
