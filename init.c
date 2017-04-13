/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:17:26 by mlambert          #+#    #+#             */
/*   Updated: 2017/04/13 21:41:05 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	reinit_after_play(t_core *core)
{
	core->map.i = 0;
	core->map.j = 0;
	core->piece.i = 0;
	core->piece.j = 0;
	core->map.visual = NULL;
	core->piece.visual = NULL;
	core->opti_y = 2147483647;
	core->opti_x = 2147483647;
	core->radar = -1;
	core->turn = 0;
}

void	player_and_nmy(t_core *core, char *line)
{
	if (line[10] == '1')
		core->player = 'O';
	else
		core->player = 'X';
	core->enemy = (core->player == 'O') ? 'X' : 'O';
}

void	little_tweak(t_core *core)
{
	core->map.i = 0;
	core->map.j = 0;
	core->piece.i = 0;
	core->piece.j = 0;
}

void	initialize(t_core *core)
{
	ft_bzero(core, sizeof(t_core));
	core->start = -1;
	core->map.visual = NULL;
	core->piece.visual = NULL;
	core->map.x = -1;
	core->map.y = -1;
	core->radar = -1;
	core->piece.x = -1;
	core->piece.y = -1;
	core->last_y = -1;
	core->last_x = -1;
	core->opti_y = 2147483647;
	core->opti_x = 2147483647;
}
