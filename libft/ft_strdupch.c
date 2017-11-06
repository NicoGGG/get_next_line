/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:48:41 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/09 16:48:43 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdupch(const char *s1, const char c)
{
	int		i;
	char	*dup;

	i = 0;
	while (s1[i] && s1[i] != c)
		i++;
	if ((dup = malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	dup[i] = 0;
	while (--i >= 0)
		dup[i] = s1[i];
	return (dup);
}
