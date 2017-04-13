/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proposition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 13:46:59 by mlambert          #+#    #+#             */
/*   Updated: 2017/04/13 21:38:27 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		compare(t_core *core, int *i, int *j)
{
	if (core->map.visual[*i][*j] == core->enemy && \
		core->piece.visual[core->piece.i][core->piece.j] == '*')
		core->nmy.block = 1;
	if (core->map.visual[*i][*j] == core->player \
		&& core->piece.visual[core->piece.i][core->piece.j] == '*')
		core->yay.block++;
	core->piece.j++;
	*j += 1;
}

int			decal(t_core *core, t_block *piece)
{
	int		i;
	int		j;

	i = core->map.i;
	j = core->map.j;
	while (piece->visual[piece->i])
	{
		while (piece->visual[piece->i][piece->j])
			compare(core, &i, &j);
		j = core->map.j;
		piece->j = 0;
		piece->i++;
		i++;
	}
	if (core->nmy.block != 0)
		return (0);
	return (core->yay.block);
}

int			proposition(t_core *core, t_block *map, t_block *piece)
{
	int		i;

	i = 0;
	while (map->visual[map->i] && (map->i + piece->y) <= map->y)
	{
		while (map->visual[map->i][map->j] && (map->j + piece->x) <= map->x)
		{
			piece->i = 0;
			piece->j = 0;
			if ((decal(core, piece) == 1))
				warpath(core);
			core->yay.block = 0;
			core->nmy.block = 0;
			map->j++;
		}
		map->j = 0;
		map->i++;
	}
	return (0);
}
