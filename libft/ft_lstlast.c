/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:28:02 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/31 17:49:17 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	if ((lst->content != NULL) && (lst->next == NULL))
		return (lst);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	if (lst->next == NULL)
		return (lst);
	return (lst);
}
/* int	main(void)
{
	t_list	*liste;
	char	dizi1[8] = "jamaika";
	char	dizi2[8] = "onceiki";
	char	dizi3[10] = "sebastian";
	char	dizi4[9] = "sonrason";

	liste = ft_lstnew(ft_strdup(dizi1));
	ft_lstadd_back(&liste, ft_lstnew(ft_strdup(dizi2)));
	printf("%s\n", ft_lstlast(liste)->content);
	ft_lstadd_back(&liste, ft_lstnew(ft_strdup(dizi3)));
	ft_lstadd_back(&liste, ft_lstnew(ft_strdup(dizi4)));
	printf("%s\n", ft_lstlast(liste)->content);
} */