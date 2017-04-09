/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rise_n_fall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 16:34:55 by mlambert          #+#    #+#             */
/*   Updated: 2017/04/09 16:44:13 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


int		fall(t_core *core)
{
	if (core



}

int		rise(t_core *core)
{
	if (core->yay.low_yi != core->map.y - 1 && core->nmy.low_yi >= core->yay.low_yi)
		ideal_set(core, core->map.y, 0);
	else if (core->yay.top_yi >= core->nmy.top_yi && core->yay.top_yi != 0)
	{
		radar(core, core->map.i, core->map.j, 0);
		ideal_set(core, 0, (0 + core->where_x));
	}
	else
		hunt(core);
}
