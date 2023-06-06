/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:38:09 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:33:08 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count ++;
	}
	return (count);
}
/*
int main()
{
	t_list **bas;
	t_list *a;
	t_list *b;
	t_list *c;
	
	bas = (t_list **)malloc(sizeof(t_list*));
	a = ft_lstnew("bu");
	b = ft_lstnew("kez");
	c = ft_lstnew("son");

	*bas = a;
	a->next = b;
	b->next = c;
	printf("%s\n%s\n%s\n", a->content, b->content, c->content);
	ft_lstsize(*bas);
	printf("size: %d", ft_lstsize(*bas));

	return(0);
}*/