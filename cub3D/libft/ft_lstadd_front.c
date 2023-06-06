/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:00:20 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:45:04 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		if (!lst)
			*lst = new;
		new->next = *lst;
		*lst = new;
	}
}

/*int main()
{
	t_list **bas;
	t_list *a;
	t_list *b;
	t_list *new;
	
	bas = (t_list **)malloc(sizeof(t_list *));
	a= ft_lstnew("birbir");
	b= ft_lstnew("ikiiki");
	new = ft_lstnew("newlst");
	
	*bas = a;                            
	a->next = b;
	ft_lstadd_front(&a, new);
	printf("%s\n", a->content);
	printf("%s\n", a->next->content);
	printf("%s\n", a->next->next->content);
	printf("%s", a->next->next->next);
}*/
