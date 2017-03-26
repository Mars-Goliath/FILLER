/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidule.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 13:46:59 by mlambert          #+#    #+#             */
/*   Updated: 2017/03/26 22:49:16 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void		compare(t_core *core, int *i, int *j)
{
// 	if (core->map.visual[*i][*j] == core->enemy && \
// 		core->piece.visual[core->piece.i][core->piece.j] == '*')
// 		core->nmy.block += 1;
// 	if (core->map.visual[*i][*j] == core->player && \
// 		core->piece.visual[core->piece.i][core->piece.j] == '*')
// 		core->yay.block += 1;
// 		core->piece.j++;
// 		*j += 1;
	if (core->map.visual[*i][*j] == core->enemy && core->piece.visual[core->piece.i][core->piece.j] == '*')
		core->nmy.block = 1;
	if (core->map.visual[*i][*j] == core->player && \
		 core->piece.visual[core->piece.i][core->piece.j] == '*')
	{
		core->yay.block++;
		printf("Truc %d %c\n", core->yay.block, core->piece.visual[core->piece.i][core->piece.j]);
	}
	core->piece.j++;
	*j += 1;
}

int			decal(t_core *core, t_block *map, t_block *piece)
{
	int		i;
	int		j;

	i = core->map.i;
	j = core->map.j;
//	printf("i %d j %d\n", i, j);
	while (piece->visual[piece->i])
	{
		while (piece->visual[piece->i][piece->j])
			compare(core, &i, &j);
		j = core->map.j;
		piece->j = 0;
		piece->i++;
		i++;
	}

//	printf("yay %d\t", core->yay.block);
//	printf("nmy %d\n", core->nmy.block);
	if (core->nmy.block != 0)
		return (0);
	return (core->yay.block);
}

int			proposition(t_core *core, t_block *map, t_block *piece)
{
	int		i;

	i = 0;
//	printf("%d map->i %d map->j \n", map->i, map->j);
//	printf("%d map->y %d map->x \n", map->y, map->x);
	while(map->visual[map->i] && (map->i + piece->y) <= map->y)
	{
		while (map->visual[map->i][map->j] && (map->j + piece->x) <= map->x)
		{
			piece->i = 0;
			piece->j = 0;
			if ((decal(core, map, piece) == 1))
				printf("... %d %d\n", map->i, map->j);
			core->yay.block = 0;
			core->nmy.block = 0;
			map->j++;
		}
		map->j = 0;
		map->i++;
	}
	while (i < map->y)
		ft_putendl(map->visual[i++]);
	i = 0;
	while (i < piece->y)
		ft_putendl(piece->visual[i++]);
	return (0);
}
