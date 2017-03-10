/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   masterplan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:10:01 by mlambert          #+#    #+#             */
/*   Updated: 2017/03/10 16:11:00 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void		display(t_core *core, int piece)
{
	int	i;

	i = 0;
	while (i < core->map.y)
		ft_putendl(core->map.visual[i++]);
	if (piece == 1)
	{
		i = 0;
		while (i < core->piece.y)
			ft_putendl(core->piece.visual[i++]);
	}
}

void		set_piece(t_core *core, int	i, int j)
{
	int	top_yi;
	int	top_xi;
	int	anchor_y;
	int	anchor_x;

 	anchor_y = core->map.i;
	anchor_x = core->map.j;
	top_yi = core->yay.top_yi;
	top_xi = core->yay.top_xi;
	i = ((i >= anchor_y) ? top_yi + (i - anchor_y) : top_yi - (anchor_y - i));
	j = ((j >= anchor_x) ? top_xi + (j - anchor_x) : top_xi - (anchor_x - j));
	core->map.visual[i][j] = core->player;
}

int		positions(t_core *core, int i, int j)
{
	int	top_yi;
	int	top_xi;
	int	anchor_y;
	int	anchor_x;

 	anchor_y = core->map.i;
	anchor_x = core->map.j;
	top_yi = core->yay.top_yi;
	top_xi = core->yay.top_xi;

	i = ((i >= anchor_y) ? top_yi + (i - anchor_y) : top_yi - (anchor_y - i));
	j = ((j >= anchor_x) ? top_xi + (j - anchor_x) : top_xi - (anchor_x - j));
//	printf("top_yi %d\n", core->yay.top_yi);
//	printf("top_xi %d\n", core->yay.top_xi);
//	printf("I %d\n", i);
//	printf("J %d\n", j);
	if (i > core->map.y || i < 0)
		return (0);
	else if (j > core->map.x || j < 0)
		return (0);
	else if (core->map.visual[i][j] != '.')
		return (0);
	return (1);
}

int			check(t_core *core, int y, int x, int draw)
{
	core->map.i = y;
	core->map.j = x;
	((x == 0) ? ((x = core->piece.x - 1) && y--) : x--);
	while (y > -1)
	{
		while (x > -1)
		{
			if (core->piece.visual[y][x] == '*')
			{
				if (draw == 0)
				{
					if (!(positions(core, y, x)))
						return (0);
				}
				else
					set_piece(core, y, x);
			}
			x--;
		}
		x = core->piece.x;
		y--;
	}
	return (1);
}

int		ladder(t_core *core, int draw)
{
	int	tmp_x;
	int	tmp_y;

	tmp_y = core->piece.y - 1;
	tmp_x = core->piece.x - 1;
	while (tmp_y != -1)
	{
		while (tmp_x != -1)
		{
			if (core->piece.visual[tmp_y][tmp_x] == '*')
				if (!(check(core, tmp_y, tmp_x, draw)))
					return (0);
			tmp_x--;
		}
		tmp_x = core->piece.x - 1;
		tmp_y--;
	}
	return (1);
}

int		scanning(t_core *core, int scan)
{
	int		i;
	int		j;
	char	id;

	i = 0;
	j = 0;
//	id = (scan == 1) ? core->enemy : core->player;
	id = core->player;
	while (core->map.visual[i])
	{
		while (core->map.visual[i][j])
		{
			if (core->map.visual[i][j] == id || \
					core->map.visual[i][j] == id - 32)
			{
				core->yay.top_yi = i;
				core->yay.top_xi = j;
				printf("I %d\n", i);
				printf("J %d\n", j);
				printf("top_yi %d\n", core->yay.top_yi);
				printf("top_xi %d\n", core->yay.top_xi);
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int		rise(t_core *core)
{
	if (!(ladder(core, 0)))
	 	return (0);
	ladder(core, 1);

	return (1);
}

void	masterplan(t_core *core, t_block *map, t_block *piece)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
//	scanning(core, 1);
	scanning(core, 0);
	printf("%s\n", "  O.O ");
	display(core, 1);


	rise(core);
	i = 0;
	j = 0;
	printf("\n");
	display(core, 0);
//	if (core->yay.top_yi <= core->nmy.top_yi)
//	else if (core->yay.top_yi > core->nmy.top_yi)
//		fall(core);

}

/*
					01234567890123456
				0	.................
				1	.................
				2	.................
				3	.................
				4	.................
				5	.................
				6	.................
				7	.................
				8	..O..............
				9	.................
				10	.................
				11	.................
				12	..............X..
				13	.................
				14	.................

				.***.
				..*..
*/
