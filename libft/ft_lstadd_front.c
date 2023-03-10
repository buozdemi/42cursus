/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:34:30 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/31 20:40:52 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*p;

	if (new == NULL)
		return ;
	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	*lst = new;
	new->next = p;
}
/* int	main(void)
{
	t_list	*liste;
	char	dizi1[8] = "ordular";
	char	dizi2[9] = "kraliyet";

	liste = ft_lstnew(ft_strdup(dizi1));
	ft_lstadd_back(&liste, ft_lstnew(ft_strdup(dizi2)));
	printf("%s\n", (char *)liste->content);
	ft_lstadd_front(&liste, ft_lstnew(ft_strdup(dizi2)));
	printf("%s", (char *)liste->content);
} */