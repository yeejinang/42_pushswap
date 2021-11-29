/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:32:13 by yang              #+#    #+#             */
/*   Updated: 2021/11/29 22:01:58 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_swap(t_info *st_info, char *line)
{
	if (!(ft_strncmp(line, "sa", ft_strlen(line))))
	{
		swap(st_info->st_a, ' ', st_info);
		return (1);
	}
	else if (!(ft_strncmp(line, "sb", ft_strlen(line))))
	{
		swap(st_info->st_b, ' ', st_info);
		return (1);
	}
	else if (!(ft_strncmp(line, "ss", ft_strlen(line))))
	{
		swap(st_info->st_a, ' ', st_info);
		swap(st_info->st_b, ' ', st_info);
		return (1);
	}
	return (0);
}

int	process_push(t_info *st_info, char *line)
{
	if (!(ft_strncmp(line, "pa", ft_strlen(line))))
	{
		push(st_info->st_a, st_info->st_b, ' ', st_info);
		return (1);
	}
	else if (!(ft_strncmp(line, "pb", ft_strlen(line))))
	{
		push(st_info->st_b, st_info->st_a, ' ', st_info);
		return (1);
	}
	return (0);
}

int	process_rotate(t_info *st_info, char *line)
{
	if (!(ft_strncmp(line, "ra", ft_strlen(line))))
	{
		rotate(st_info->st_a, ' ', st_info);
		return (1);
	}
	else if (!(ft_strncmp(line, "rb", ft_strlen(line))))
	{
		rotate(st_info->st_b, ' ', st_info);
		return (1);
	}
	else if (!(ft_strncmp(line, "rr", ft_strlen(line))))
	{
		rotate(st_info->st_a, ' ', st_info);
		rotate(st_info->st_b, ' ', st_info);
		return (1);
	}
	return (0);
}

int	process_reverse(t_info *st_info, char *line)
{
	if (!(ft_strncmp(line, "rra", 3)))
	{
		reverse_rotate(st_info->st_a, ' ', st_info);
		return (1);
	}
	else if (!(ft_strncmp(line, "rrb", 3)))
	{
		reverse_rotate(st_info->st_b, ' ', st_info);
		return (1);
	}
	else if (!(ft_strncmp(line, "rrr", 3)))
	{
		reverse_rotate(st_info->st_a, ' ', st_info);
		reverse_rotate(st_info->st_b, ' ', st_info);
		return (1);
	}
	return (0);
}
