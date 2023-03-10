/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:47:07 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/31 18:17:33 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;

	if (!*lst || !del || !lst)
		return ;
	while (*lst != NULL)
	{
		p = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = p;
	}
}
/* void	del(void *p)
{
	free(p);
}
int	main(void)
{
	t_list	*liste;
	char	dizi1[4] = "cok";
	char	dizi2[4] = "max";
	char	dizi3[4] = "ask";
	char	dizi4[4] = "lib";

	liste = ft_lstnew(ft_strdup(dizi1));
	ft_lstadd_back(&liste, ft_lstnew(ft_strdup(dizi2)));
	ft_lstadd_back(&liste, ft_lstnew(ft_strdup(dizi3)));
	ft_lstadd_back(&liste, ft_lstnew(ft_strdup(dizi4)));
	printf("%s\n", liste->content);
	ft_lstclear(&liste, del);
	printf("%s\n", liste->content);
	if (liste)
		printf("BASARILI\n");
} */