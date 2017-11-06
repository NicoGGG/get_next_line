/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchfree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 18:20:49 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/06 18:20:50 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoinchfree(char *s1, char const *s2, char const c)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j] && s2[j] != c)
		j++;
	if ((join = malloc(sizeof(char) * (i + j) + 1)) == NULL)
		return (NULL);
	join[i + j] = 0;
	while (--j >= 0)
		join[i + j] = s2[j];
	while (--i >= 0)
		join[i] = s1[i];
	ft_memdel((void **)&s1);
	return (join);
}
