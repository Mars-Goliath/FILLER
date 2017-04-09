/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 23:29:17 by mlambert          #+#    #+#             */
/*   Updated: 2017/04/09 16:13:33 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

/*void	scanning(t_core *core, int scan)
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
			if (core->map.visual[i][j] == id)
				break ;
			j++;
		}
		core->yay.top_yi = scan == 0 ? i : core->yay.top_yi;
		core->yay.top_xi = scan == 0 ? j : core->yay.top_xi;
		j = 0;
		i++;
	}
//	core->yay.top_yi = scan == 1 ? i : core->enemy.top_yi;
//	core->yay.top_xi = scan == 1 ? j : core->enemy.top_xi;
}*/

/*void	masterplan(t_core *core, t_block *map, t_block *piece)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	scanning(core, 0);
	scanning(core, 1);
		while (i < core->map.y)
		ft_putendl(core->map.visual[i++]);
	while (j < core->piece.y)
		ft_putendl(core->piece.visual[j++]);
	i = 0;
	j = 0;
	while (core->piece.visual[i])
	{
		while (core->piece.visual[i][j])
		{
			if (core->piece.visual[i][j] == '*')
				core->map.visual[core->yay.top_yi][core->yay.top_xi--] = core->map.visual[i][j];
			j++;
		}
		j = 0;
		i++;
	}
 	i = 0;
	j = 0;
	while (i < core->map.y)
		ft_putendl(core->map.visual[i++]);
//	while (j < core->piece.y)
	//	ft_putendl(core->piece.visual[j++]);

}*/

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
	{
		if (core->map.y > 40 && core->start == 1)
			core->start = 2;
		else if (core->map.y > 40 && core->start == 2)
			core->start = 1;

		core->turn = 1;
	}
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
		// core->nb_near = -1;
		// core->near_x = -1;
		// core->near_y = -1;
	}
	if (size_init_piece == 2)
	{
		while (line[i++] != 32);
		core->piece.y = ft_atoi(&line[i]);
		while (line[i++] != 32);
		core->piece.x = ft_atoi(&line[i]);
	}
}

int			filler(void)
{
	t_core core;
	char	*line;
	int		ret;

/*	size_init_piece(&core, line, 1);
	while (get_next_line(0, &line) > 0)
	{
		if (core.player == 0 && *line == 'l')
		{
			core.player = (ft_strstr(line, "mlambert")) ? 'O' : 'X';
			core.enemy = (core.player == 'o') ? 'X' : 'O';
		}
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
		{
			core.map.i = 0;
			core.map.j = 0;
			core.piece.i = 0;
			core.piece.j = 0;
			masterplan(&core, &core.map, &core.piece);
			core.turn = 1;
			printf("%d %d\n", core.opti_y, core.opti_x);
			return (0);
		}
	}*/
	return (0);
}

int 	main(int argc, char **argv)
{
	t_core core;
	char	*line;
	int		ret;

	size_init_piece(&core, line, 1);
	while (get_next_line(0, &line))
	{
		// ft_putstr_fd(ft_itoa(core.turn), 2);
		// ft_putstr_fd("\n", 2);
		if (core.turn == 1)
		{
		//	ft_putstr_fd("ZANZIBAR", 2);
			core.map.i = 0;
			core.map.j = 0;
			core.piece.i = 0;
			core.piece.j = 0;
			core.map.visual = NULL;
			core.piece.visual = NULL;
 			core.opti_y = 2147483647;
			core.opti_x = 2147483647;
			core.radar = -1;
			core.turn = 0;
		}
		if (core.player == 0 && line[9] == 'p')
		{
			line[10] == '1' ? (core.player = 'O') : (core.player = 'X');
			core.enemy = (core.player == 'O') ? 'X' : 'O';
		}
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
		{
			core.map.i = 0;
			core.map.j = 0;
			core.piece.i = 0;
			core.piece.j = 0;
			masterplan(&core, &core.map, &core.piece);
			ft_putnbr(core.opti_y);
			ft_putchar(32);
			ft_putnbr(core.opti_x);
			ft_putchar('\n');
		}
		ft_memdel((void**)&line);
	}
	return (0);
}
