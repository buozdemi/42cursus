/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:35:15 by buozdemi          #+#    #+#             */
/*   Updated: 2022/02/20 14:35:18 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
void	ft_put_base(unsigned int nbr, \
		const char *base, int hexa_type, int *count);
void	ft_put_pointer(unsigned long long n, int *count);
int		ft_putchar_newfd(char c, int fd);
void	ft_putnbr_newfd(int n, int fd, int *count);
int		ft_putstr_newfd(char *str, int fd);

#endif
