/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 20:29:05 by mlambert          #+#    #+#             */
/*   Updated: 2017/04/13 21:56:07 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	reinit_side(int *n, int *y, int *i, int *j)
{
	*n += 2;
	*y -= 1;
	*i = 0;
	*j = 0;
}

void	reinit(int *n, int *i, int *y, int *x)
{
	*n += 2;
	*i = 0;
	*x -= 1;
	*y -= 1;
}
