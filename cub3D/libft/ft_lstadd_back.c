/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:59:12 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:50:13 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		end = ft_lstlast(*lst);
		end->next = new;
	}
}
/*
int main()
{
	t_list **bas;
	t_list *a;
	t_list *b;
	t_list *last;
	
	bas = (t_list **)malloc(sizeof(t_list *));
	a = ft_lstnew("ecole");
	b = ft_lstnew("aysu");
	last = ft_lstnew("finalnode");
	
	*bas = a;
	a->next = b;
	
	ft_lstadd_back(&a, last);
	printf("%s\n", a->content);
	printf("%s\n", a->next->content);
	printf("%s\n", a->next->next->content);
}*/
