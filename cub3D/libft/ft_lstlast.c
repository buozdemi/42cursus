/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:50:05 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:44:00 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*int main()
{
	t_list **bas;
	t_list *a;
	t_list *b;
	t_list *c;
	t_list *k;
	
	bas = (t_list **)malloc(sizeof(t_list*));
	a = ft_lstnew("hadi");
	b = ft_lstnew("bakalim");
	c = ft_lstnew("neolcak");
	
	*bas = a;
	a->next = b;
	b->next = c;
	
	k = ft_lstlast(*bas);
	
	printf("%s", k->content);
	return(0);
}*/