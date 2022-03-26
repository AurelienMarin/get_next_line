/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:22:33 by aumarin           #+#    #+#             */
/*   Updated: 2022/03/20 00:40:03 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h> 
#include <string.h>

int	main(int ac, char **av)
{
	int		i;
	char	*txt;
	int		fd;

	(void)ac;
	i = 0;
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	fd = open(av[1], O_RDONLY);
	txt = malloc(sizeof(char) * 1);
	while (txt)
	{
		i++;
		txt = get_next_line(fd);
		
		if (txt) {printf("%d)%s", i, txt);
			free(txt);}
		else
			printf("\n%d(null)", i);
	}
	return (0);
}
