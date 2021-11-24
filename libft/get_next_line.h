/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:17:11 by yang              #+#    #+#             */
/*   Updated: 2021/11/24 15:05:59 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <errno.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# ifndef MAX_FILE
#  define MAX_FILE 65536
# endif

int		get_next_line(int fd, char **line);
int		next_line(int fd, char **content, char **line);
void	*ft_calloc1(size_t count, size_t size);
char	*ft_substr1(char const *s, unsigned int start, size_t len);
char	*ft_strchr1(const char *s, int c);
char	*ft_strjoin1(char const *s1, char const *s2);
char	*ft_strdup1(const char *s1);

#endif