/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:09:07 by buozdemi          #+#    #+#             */
/*   Updated: 2022/05/14 18:10:30 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "ftprintf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_allnum
{
	int		charcount;
	char	*allchar;
	int		*a;
	int		*b;
	size_t	intnumbersa;
	size_t	intnumbersb;
	size_t	m;
	int		thebiggestnumber;
	int		*ai;
	int		thebiggestnumberai;
	size_t	thebiggestnumindexi;
	int		malgminnumber;
	size_t	malgminindex;
	int		info;
	int		emptystring;
	int		mark;
	int		afterbiggestnum;
}	t_allnum;

int		ft_atoi(const char *str, t_allnum *allnum);
size_t	ft_strlenline(char **s);
int		argconv(char **argv, t_allnum *allnum);
int		intnumberfunc(char **argv, t_allnum *allnum);
void	intnumberfunc2(t_allnum *allnum);
int		digitordigits(char **argv, int i);
int		ft_whichdigit(int c);
void	convonlydigit(char *s, t_allnum *allnum);
void	spacedigit(char *s, t_allnum *allnum);
void	howmchar(char **argv, t_allnum *allnum);
void	samenumber(int a, t_allnum *allnum);
void	swapa(t_allnum *allnum);
void	swapb(t_allnum *allnum);
void	pusha(t_allnum *allnum);
void	pushb(t_allnum *allnum);
void	rotatea(t_allnum *allnum);
void	rotateb(t_allnum *allnum);
void	reverserotatea(t_allnum *allnum);
void	reverserotateb(t_allnum *allnum);
void	sssw(t_allnum *allnum);
void	rrab(t_allnum *allnum);
void	rrrab(t_allnum *allnum);
void	radixalgorithm(t_allnum *allnum);
int		thebiggestbit(int n);
void	toconvertindex(t_allnum *allnum);
void	smallgorithm(t_allnum *allnum);
void	smallgorithm2(t_allnum *allnum);
int		arithmean(t_allnum *allnum);
void	thebiggestnum(t_allnum *allnum);
void	minialgorithm(t_allnum *allnum);
void	minialgorithm2(t_allnum *allnum);
void	malgminnumber(t_allnum *allnum);
int		maintheme(t_allnum *allnum, char **argv);
void	stringstate(char **argv, t_allnum *allnum, int i, int m);
void	stringstate2(t_allnum *allnum);
void	writehowmchar(char **argv, t_allnum *allnum);
void	rescontrol(long res, t_allnum *allnum);
void	contiguous(t_allnum *allnum);
int		ordinalnum(t_allnum *allnum);
void	onlythreenum(t_allnum *allnum);
void	ifminindex2(t_allnum *allnum);
void	ifminindex1(t_allnum *allnum);
void	ifminindex0(t_allnum *allnum);
void	secondpartfree(t_allnum *allnum);
void	afterbiggestnum(t_allnum *allnum);

#endif