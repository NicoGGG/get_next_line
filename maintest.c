/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:01:41 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/23 14:30:50 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("a.out", O_RDONLY);
	printf("fd = %d\n", fd);
	while (get_next_line(fd, &line) > 0)
		printf("%s\n", line);
	return (0);
}
