#include "libft.h"

static t_list	*freelist(t_list *lst, void (*del)(void *))
{
	ft_lstclear(&lst, del);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;

	if (f == 0 || del == 0)
		return (0);
	result = ft_lstnew((*f)(lst->content));
	if (result == 0)
		return (0);
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (temp == 0)
			return (freelist(result, del));
		ft_lstadd_back(&result, temp);
		lst = lst->next;
	}
	return (result);
}
