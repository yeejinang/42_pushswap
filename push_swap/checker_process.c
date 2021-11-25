/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:32:13 by yang              #+#    #+#             */
/*   Updated: 2021/11/25 14:09:52 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	process_swap(t_info *st_info, char *line)
{
	if (ft_strncmp(line, "sa", 2) == 0)
	{
		swap(st_info->st_a, ' ', st_info);
		return (1);
	}
	else if (ft_strncmp(line, "sb", 2) == 0)
	{
		swap(st_info->st_b, ' ', st_info);
		return (1);
	}
	else if (ft_strncmp(line, "ss", 2) == 0)
	{
		swap(st_info->st_a, ' ', st_info);
		swap(st_info->st_b, ' ', st_info);
		return (1);
	}
	return (0);
}

int	process_push(t_info *st_info, char *line)
{
	if (ft_strncmp(line, "pa", 2) == 0)
	{
		push(st_info->st_a, st_info->st_b, ' ', st_info);
		return (1);
	}
	else if (ft_strncmp(line, "pb", 2) == 0)
	{
		push(st_info->st_b, st_info->st_a, ' ', st_info);
		return (1);
	}
	return (0);
}

int	process_rotate(t_info *st_info, char *line)
{
	if (ft_strncmp(line, "ra", 2) == 0)
	{
		rotate(st_info->st_a, ' ', st_info);
		return (1);
	}
	else if (ft_strncmp(line, "rb", 2) == 0)
	{
		rotate(st_info->st_b, ' ', st_info);
		return (1);
	}
	else if (ft_strncmp(line, "rr", 2) == 0)
	{
		rotate(st_info->st_a, ' ', st_info);
		rotate(st_info->st_b, ' ', st_info);
		return (1);
	}
	return (0);
}

int	process_reverse(t_info *st_info, char *line)
{
	if (ft_strncmp(line, "rra", 3) == 0)
	{
		reverse_rotate(st_info->st_a, ' ', st_info);
		return (1);
	}
	else if (ft_strncmp(line, "rrb", 3) == 0)
	{
		reverse_rotate(st_info->st_b, ' ', st_info);
		return (1);
	}
	else if (ft_strncmp(line, "rrr", 3) == 0)
	{
		reverse_rotate(st_info->st_a, ' ', st_info);
		reverse_rotate(st_info->st_b, ' ', st_info);
		return (1);
	}
	return (0);
}
