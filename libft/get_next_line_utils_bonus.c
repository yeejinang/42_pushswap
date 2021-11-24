/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:59:21 by yang              #+#    #+#             */
/*   Updated: 2021/11/24 15:08:07 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc1(size_t count, size_t size)
{
	void	*ptr;
	int		len;
	char	*str;

	ptr = (void *)malloc(count * size);
	if (ptr)
	{
		len = count * size;
		str = ptr;
		while (len--)
			*str++ = '\0';
		return (ptr);
	}
	else
		return (NULL);
}

char	*ft_substr1(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*src;
	size_t	i;

	ptr = (char *)malloc(len + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	src = (char *)s + start;
	i = 0;
	while (*src && i < len)
		ptr[i++] = *src++;
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr1(const char *s, int c)
{
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	while (*ptr != c)
	{
		if (*ptr == '\0')
			return (NULL);
		ptr++;
	}
	return ((char *)ptr);
}

char	*ft_strjoin1(char const *s1, char const *s2)
{
	size_t	sum_length;
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	s2_len = 0;
	while (s2[s2_len])
		s2_len++;
	sum_length = s1_len + s2_len;
	ptr = (char *)malloc(sizeof(char) * sum_length + 1);
	if (ptr == NULL)
		return (NULL);
	s = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (s);
}

char	*ft_strdup1(const char *s1)
{
	char	*dest;
	int		i;
	int		length;

	length = 0;
	while (s1[length] != '\0')
		length++;
	dest = (char *)malloc(sizeof(char) * length + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
