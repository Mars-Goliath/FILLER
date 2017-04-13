/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 22:57:46 by mlambert          #+#    #+#             */
/*   Updated: 2017/04/13 21:55:40 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ideal_set(t_core *core, int ideal_y, int ideal_x)
{
	if (ABS(core->map.i - ideal_y) < ABS(core->opti_y - ideal_y))
	{
		core->opti_y = core->map.i;
		core->opti_x = core->map.j;
	}
	else if (ABS(core->map.i - ideal_y) == ABS(core->opti_y - ideal_y))
		if (ABS(core->map.j - ideal_x) < ABS(core->opti_x - ideal_x))
		{
			core->opti_y = core->map.i;
			core->opti_x = core->map.j;
		}
}

int		echo_side(t_core *core, int y, int x, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (y >= 0)
	{
		while (i != core->piece.y + n && core->map.visual[y + i])
		{
			while (j != core->piece.x + n && core->map.visual[y + i][x + j])
			{
				if (core->map.visual[y + i][x + j] == core->enemy)
				{
					core->where_x = (x + j);
					return ((n == 0) ? 0 : n / 2);
				}
				j++;
			}
			j = 0;
			i++;
		}
		reinit_side(&n, &y, &i, &j);
	}
	return (n);
}

int		radar(t_core *core, int y, int x, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (y >= 0 && x >= 0)
	{
		while (i != core->piece.y + n && core->map.visual[y + i])
		{
			while (j != core->piece.x + n && core->map.visual[y + i][x + j])
			{
				if (core->map.visual[y + i][x + j] == core->enemy)
					return ((n == 0) ? 0 : n / 2);
				j++;
			}
			j = 0;
			i++;
		}
		reinit(&n, &i, &y, &x);
	}
	i = core->map.i;
	j = core->map.j;
	return (echo_side(core, i, j, 0));
}

void	hunt(t_core *core)
{
	int		echo;

	echo = radar(core, core->map.i, core->map.j, 0);
	if (core->radar == -1)
	{
		core->radar = echo;
		core->opti_y = core->map.i;
		core->opti_x = core->map.j;
	}
	else if (core->radar > echo)
	{
		core->radar = echo;
		core->opti_y = core->map.i;
		core->opti_x = core->map.j;
	}
}

int		warpath(t_core *core)
{
	scanning(core, 0);
	scanning(core, 1);
	scanning_low(core, 0);
	scanning_low(core, 1);
	if (core->start == -1)
		core->start = core->yay.top_xi < core->nmy.top_xi ? 1 : 2;
	if (core->opti_y == 2147483647 && core->opti_x == 2147483647)
	{
		core->opti_y = core->map.i;
		core->opti_x = core->map.j;
	}
	if (core->yay.low_yi != core->map.y - 1 && \
		core->nmy.low_yi >= core->yay.low_yi)
		ideal_set(core, core->nmy.low_yi, (core->nmy.low_xi));
	else if (core->yay.top_yi >= core->nmy.top_yi && core->yay.top_yi != 0)
	{
		core->angle_x = x_angle(core);
		ideal_set(core, 0, (core->start == 1 ? \
		core->map.x : (0 + core->angle_x)));
	}
	else
		hunt(core);
	return (0);
}
