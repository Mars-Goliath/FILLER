/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 23:29:17 by mlambert          #+#    #+#             */
/*   Updated: 2017/04/12 19:05:16 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		visuals(t_core *core, char *line, int piece)
{
	int i;
	int	j;
	t_block *block;

	i = 0;
	j = 0;
	while ((ft_isdigit(line[j]) || line[j] == 32))
		j++;
	block = (piece == 1) ? &core->piece : &core->map;
	if (block->visual == NULL)
	{
		if (!(block->visual = (char**)malloc(sizeof(char *) * (block->y + 1))))
			return (-1);
		block->visual[block->y] = NULL;
	}
	if (block->i <= block->y)
		if (!(block->visual[block->i++] = ft_strdup(&line[j])))
			return (-1);
	if (piece == 1 && block->i == block->y)
		core->turn = 1;
	block = NULL;
	free(block);
	return (0);
}


void	size_init_piece(t_core *core, char *line, int size_init_piece)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	if (size_init_piece == 0)
	{
		while (line[i++] != 32);
		core->map.y = ft_atoi(&line[i]);
		while (line[i++] != 32);
		core->map.x = ft_atoi(&line[i]);
	}
	if (size_init_piece == 1)
		initialize(core);
	if (size_init_piece == 2)
	{
		while (line[i++] != 32);
		core->piece.y = ft_atoi(&line[i]);
		while (line[i++] != 32);
		core->piece.x = ft_atoi(&line[i]);
	}
}

void	filler(t_core *core)
{
	little_tweak(core);
	proposition(core, &core->map, &core->piece);
	ft_printf("%d %d\n", core->opti_y, core->opti_x);
}

int 	main(int argc, char **argv)
{
	t_core 	core;
	char	*line;
	int		ret;

	size_init_piece(&core, line, 1);
	while (get_next_line(0, &line))
	{
		if (core.turn == 1)
			reinit_after_play(&core);
		if (core.player == 0 && line[9] == 'p')
			player_and_nmy(&core, line);
		if (*(line + 1) == 'l' && core.map.y == -1 && core.map.x == -1)
			size_init_piece(&core, line, 0);
		if (ft_isdigit(*line))
			if (visuals(&core, line, 0) == -1)
				return (0);
		if (*(line + 1) == 'i')
			size_init_piece(&core, line, 2);
		if (*line == '.' || *line == '*')
			if (visuals(&core, line, 1))
				return (0);
		if (core.turn == 1)
			filler(&core);
		ft_memdel((void**)&line);
	}
	return (0);
}
