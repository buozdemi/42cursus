/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:49:39 by buozdemi          #+#    #+#             */
/*   Updated: 2022/06/11 18:45:35 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	key_press_r(t_map *a)
{
	if (a->line[a->i][a->m + 1] != '1')
	{
		if (a->line[a->i][a->m + 1] == 'C')
		{
			mlx_put_image_to_window(a->mlx, a->win, a->b, a->m * 64, a->i * 64);
			mlx_put_image_to_window(a->mlx, a->win, a->b, (a->m + 1) * 64, \
			(a->i) * 64);
			mlx_put_image_to_window(a->mlx, a->win, a->scorig, (++a->m) * 64, \
			(a->i) * 64);
			a->line[a->i][a->m] = '0';
			a->totalc += 1;
			a->step += 1;
			ft_printf("%d\n", a->step);
		}
		else if (a->line[a->i][a->m + 1] != 'E')
		{
			mlx_put_image_to_window(a->mlx, a->win, a->b, a->m * 64, a->i * 64);
			mlx_put_image_to_window(a->mlx, a->win, a->scorig, (++a->m) * 64, \
			(a->i) * 64);
			a->step += 1;
			ft_printf("%d\n", a->step);
		}
		else if (a->line[a->i][a->m + 1] == 'E' && (a->totalc == a->existc))
			doorandexitfree(a);
	}
}

void	key_press_l(t_map *a)
{
	if (a->line[a->i][a->m - 1] != '1')
	{
		if (a->line[a->i][a->m - 1] == 'C')
		{
			mlx_put_image_to_window(a->mlx, a->win, a->b, a->m * 64, a->i * 64);
			mlx_put_image_to_window(a->mlx, a->win, a->b, (a->m - 1) * 64, \
			(a->i) * 64);
			mlx_put_image_to_window(a->mlx, a->win, a->scolef, (--a->m) * 64, \
			(a->i) * 64);
			a->line[a->i][a->m] = '0';
			a->totalc += 1;
			a->step += 1;
			ft_printf("%d\n", a->step);
		}
		else if (a->line[a->i][a->m - 1] != 'E')
		{
			mlx_put_image_to_window(a->mlx, a->win, a->b, a->m * 64, a->i * 64);
			mlx_put_image_to_window(a->mlx, a->win, a->scolef, (--a->m) * 64, \
			(a->i) * 64);
			a->step += 1;
			ft_printf("%d\n", a->step);
		}
		else if (a->line[a->i][a->m - 1] == 'E' && (a->totalc == a->existc))
			doorandexitfree(a);
	}
}

void	key_press_u(t_map *a)
{
	if (a->line[a->i - 1][a->m] != '1')
	{
		if (a->line[a->i - 1][a->m] == 'C')
		{
			mlx_put_image_to_window(a->mlx, a->win, a->b, a->m * 64, a->i * 64);
			mlx_put_image_to_window(a->mlx, a->win, a->b, (a->m) * 64, \
			(a->i - 1) * 64);
			mlx_put_image_to_window(a->mlx, a->win, a->scob, (a->m) * 64, \
			(--a->i) * 64);
			a->line[a->i][a->m] = '0';
			a->totalc += 1;
			a->step += 1;
			ft_printf("%d\n", a->step);
		}
		else if (a->line[a->i - 1][a->m] != 'E')
		{
			mlx_put_image_to_window(a->mlx, a->win, a->b, a->m * 64, a->i * 64);
			mlx_put_image_to_window(a->mlx, a->win, a->scob, (a->m) * 64, \
			(--a->i) * 64);
			a->step += 1;
			ft_printf("%d\n", a->step);
		}
		else if (a->line[a->i - 1][a->m] == 'E' && (a->totalc == a->existc))
			doorandexitfree(a);
	}
}

void	key_press_d(t_map *a)
{
	if (a->line[a->i + 1][a->m] != '1')
	{
		if (a->line[a->i + 1][a->m] == 'C')
		{
			mlx_put_image_to_window(a->mlx, a->win, a->b, a->m * 64, a->i * 64);
			mlx_put_image_to_window(a->mlx, a->win, a->b, (a->m) * 64, \
			(a->i + 1) * 64);
			mlx_put_image_to_window(a->mlx, a->win, a->scofield, (a->m) * 64, \
			(++a->i) * 64);
			a->line[a->i][a->m] = '0';
			a->totalc += 1;
			a->step += 1;
			ft_printf("%d\n", a->step);
		}
		else if (a->line[a->i + 1][a->m] != 'E')
		{
			mlx_put_image_to_window(a->mlx, a->win, a->b, a->m * 64, a->i * 64);
			mlx_put_image_to_window(a->mlx, a->win, a->scofield, (a->m) * 64, \
			(++a->i) * 64);
			a->step += 1;
			ft_printf("%d\n", a->step);
		}
		else if (a->line[a->i + 1][a->m] == 'E' && (a->totalc == a->existc))
			doorandexitfree(a);
	}
}
