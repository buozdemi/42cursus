/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:45:23 by buozdemi          #+#    #+#             */
/*   Updated: 2022/02/01 16:29:39 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{	
	t_list	*new_lst;
	t_list	*new_node;

	new_lst = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
/* 
void	sil(void *p)
{
	free(p);
}

void	*benimfonk(void *c)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)c;
	while (p[i] != '\0')
	{
		p[i++] = 'Y';
	}
	p[i] = '\0';
	return ("ahmet");
}

int	main(void)
{
	t_list	*liste;
	char	dizi1[4] = "cok";
	char	dizi2[4] = "tok";
	char	dizi3[4] = "yok";
	t_list	*adana;

	liste = ft_lstnew(ft_strdup(dizi1));
	ft_lstadd_back(&liste, ft_lstnew(ft_strdup(dizi2)));
	ft_lstadd_back(&liste, ft_lstnew(ft_strdup(dizi3)));
	adana = ft_lstmap(liste, benimfonk, sil);
	printf("%s\n", adana->content);
	printf("%s\n", ft_lstlast(adana)->content);
	printf("%s\n", ft_lstlast(liste)->content);
}  */