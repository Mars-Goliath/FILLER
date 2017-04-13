/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mind_reading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:59:19 by mlambert          #+#    #+#             */
/*   Updated: 2017/04/13 21:59:27 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	low(t_core *core int scan, int i, int j)
{
	if (scan == 0)
	{
		core->yay.low_yi = i;
		core->yay.low_xi = j;
	}
	else
	{
		core->nmy.low_yi = i;
		core->nmy.low_xi = j;
	}
}

void	top(t_core *core int scan, int i, int j)
{
	if (scan == 0)
	{
		core->yay.top_yi = i;
		core->yay.top_xi = j;
	}
	else
	{
		core->nmy.top_yi = i;
		core->nmy.top_xi = j;
	}
}

int		x_angle(t_core *core)
{
	int		i;
	int		j;
	int		closest;

	i = 0;
	j = core->map.x;
	closest = 0;
	while (core->map.visual[i] && i != core->yay.top_yi)
	{
		while (j-- != 0)
		{
			if (core->map.visual[i][j] == core->enemy)
				closest = (j > closest) ? j : closest;
		}
		j = core->map.x;
		i++;
	}
	return (closest);
}

int		scanning_low(t_core *core, int scan)
{
	int		i;
	int		j;
	char	id;

	i = core->map.y - 1;
	j = core->map.x - 1;
	id = scan == 0 ? core->player : core->enemy;
	while (i != 0)
	{
		while (j != 0)
		{
			if (core->map.visual[i][j] == id)
			{
				low(core, scan, i, j);
				return (1);
			}
			j--;
		}
		j = core->map.x - 1;
		i--;
	}
	return (0);
}

int		scanning(t_core *core, int scan)
{
	int		i;
	int		j;
	char	id;

	i = 0;
	j = 0;
	id = scan == 0 ? core->player : core->enemy;
	while (core->map.visual[i])
	{
		while (core->map.visual[i][j])
		{
			if (core->map.visual[i][j] == id)
			{
				top(core, scan, i, j);
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
