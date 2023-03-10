/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:17:19 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/31 17:51:27 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
	{	
		*lst = new;
		return ;
	}
	p = ft_lstlast(*lst);
	p->next = new;
}
/* int	main(void)
{
	t_list	*liste;
	char	dizi1[8] = "legolas";
	char	dizi2[8] = "jonsnow";
	char	dizi3[10] = "lannister";
	char	dizi4[15] = "sonuncudegisti";

	liste = ft_lstnew(ft_strdup(dizi1));
	liste->next = ft_lstnew(ft_strdup(dizi2));
	liste->next->next = ft_lstnew(ft_strdup(dizi3));
	printf("%s\n", (char *)ft_lstlast(liste)->content);
	ft_lstadd_back(&liste, ft_lstnew(ft_strdup(dizi4)));
	printf("%s\n", (char *)ft_lstlast(liste)->content);
} */