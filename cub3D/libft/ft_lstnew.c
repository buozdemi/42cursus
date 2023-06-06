/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:31:35 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:34:14 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
int main()
{
	t_list **bas;
	t_list *a;
	t_list *b;
	t_list *c;
	
	bas = (t_list **)malloc(sizeof(t_list *));
	a = ft_lstnew("aysuoner.");
	b = ft_lstnew("ecole");
	c = ft_lstnew("42");
	
	*bas = a;
	a->next = b;
	b->next = c;
	
	printf("%s\n", (*bas)->content);
	printf("%s\n", (*bas)->next->content);
	printf("%s\n", (*bas)->next->next->content);
	printf("%s", (*bas)->next->next->next);
}*/