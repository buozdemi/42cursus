/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:19:33 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/31 17:48:22 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	if (lst == NULL)
		return (0);
	if ((lst->content != NULL) && (lst->next == NULL))
		return (1);
	while (lst->next != NULL)
	{
		lst = lst->next;
		len++;
	}
	if (lst->next == NULL)
		return (len + 1);
	return (0);
}

/* int	main(void)
{
	t_list	*liste;
	char	dizi1[8] = "ordular";
	char	dizi2[9] = "kraliyet";
	char	dizi3[7] = "hasbro";

	liste = ft_lstnew(ft_strdup(dizi1));
	ft_lstadd_back(&liste, ft_lstnew(ft_strdup(dizi2)));
	ft_lstadd_back(&liste, ft_lstnew(ft_strdup(dizi3)));
	printf("%d", ft_lstsize(liste));
} */