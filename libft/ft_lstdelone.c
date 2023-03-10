/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:45:20 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/24 19:45:20 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}
/* void	del(void *p)
{
	free(p);
}
int	main(void)
{
	t_list	*liste;
	char	dizi1[8] = "boyutlu";
	char	dizi2[8] = "doyumlu";

	liste = ft_lstnew(ft_strdup(dizi1));
	ft_lstadd_back(&liste, ft_lstnew(ft_strdup(dizi2)));
	printf("%s\n", liste->content);
	ft_lstdelone(liste, del);
	printf("%s\n", liste->content);
} */