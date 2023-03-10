/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:38:15 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/30 19:28:16 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst->next != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
	if (lst->next == NULL)
		f(lst->content);
}
/* void	f(void *p)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)p;
	while (str[i] != '\0')
	{
		str[i++] = 'Y';
	}
}
int	main(void)
{
	t_list	*liste;
	char	dizi1[4] = "cok";
	char	dizi2[4] = "max";
	char	dizi3[4] = "flu";

	liste = ft_lstnew(ft_strdup(dizi1));
	ft_lstadd_back(&liste, ft_lstnew(ft_strdup(dizi2)));
	ft_lstadd_back(&liste, ft_lstnew(ft_strdup(dizi3)));
	printf("%s\n", liste->content);
	ft_lstiter(liste, f);
	printf("%s\n", liste->content);
} */