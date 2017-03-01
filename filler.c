/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 23:29:17 by mlambert          #+#    #+#             */
/*   Updated: 2017/03/01 12:03:07 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int		visuals(t_core *core, char *line, int piece)
{
	int i;
	int	j;
	t_block *block;

	i = 0;
	j = 0;
	while ((line[j] == 32) || (ft_isdigit(*line)))
		line[j++];
	block = (piece == 1) ? &core->piece : &core->map;
	if (block->visual[i] == NULL)
		if (!(block->visual = (char**)malloc(sizeof(char *) * block->y)))
			return (-1);
	if (block->i < block->y)
		if (!(block->visual[block->i++] = ft_strdup(&line[j])))
			return (-1);
	if (piece == 1 && block->i == block->y)
		core->turn = 1;
	return (0);
}


void	size_init_piece(t_core *core, int size_init_piece)
{
	int	i;

	i = 0;
	if (size_init_piece == 0)
	{
		core->map.y = ft_atoi(&line[i]);
		while (line[i] != 32)
			i++;
		core->map.x = ft_atoi(&line[i]);
	}
	if (size_init_piece == 1)
	{
		ft_bzero(&core);
		core->map->x = -1;
		core->map->y = -1;
		core->piece->x = -1;
		core->map->y = -1;
	}
	if (size_init_piece == 2)
	{


	}
}

int			filler(int fd)
{
	t_core core;
	char	*line;

	line = NULL;
	size_init_piece(&core, 1);
	while (gnl(fd, &line))
	{
		if (core->player == 0)
			core->player = (strstr(line, "mlambert")) ? 'o' : 'x';
		if (*(line + 1) == 'l' && core.map.y == -1 && core.map.x == -1)
			size_init_piece(core, line, 0);
		if (ft_isdigit(*line))
			if (visuals(&core, line, 0) == -1)
				return (0);
		if (*line == '.' || *line == '*')
			if (visuals(&core, line, 1))
				return (0);
		if (core->turn == 1)
			masterplan(&core);
	}
}
