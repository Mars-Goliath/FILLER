/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:26:43 by mlambert          #+#    #+#             */
/*   Updated: 2016/11/14 14:39:31 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = (char *)s;
	while (i < n)
	{
		tab[i] = '\0';
		i++;
	}
}
