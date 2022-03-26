/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:11:23 by aumarin           #+#    #+#             */
/*   Updated: 2022/03/26 16:15:53 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/**
 *	INCLUDES
 */

# include <stdlib.h>
# include <unistd.h>

/**
 *	DEFINITIONS
 */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/**
 *	PROTOTYPES 
 */
void	ft_bzero(void *s, size_t n);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif