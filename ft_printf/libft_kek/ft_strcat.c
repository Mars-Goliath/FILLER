/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:32:11 by mlambert          #+#    #+#             */
/*   Updated: 2016/11/11 16:44:15 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	s;

	s = 0;
	i = ft_strlen(s1);
	if (s1 == NULL)
		return (NULL);
	while (s2[s])
	{
		s1[i] = s2[s];
		i++;
		s++;
	}
	s1[i] = '\0';
	return (s1);
}
