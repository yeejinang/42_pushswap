/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:11:08 by yang              #+#    #+#             */
/*   Updated: 2021/11/30 14:07:04 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_instru(t_info *st_info, char *str)
{
	free(st_info->last);
	st_info->last = NULL;
	free(st_info->instru);
	st_info->instru = NULL;
	st_info->last = ft_strdup(str);
}

void	print_null(t_info *st_info, int len_last, int len_instru)
{
	if ((!(ft_strncmp(st_info->last, "pa\n", len_last))
			&& !(ft_strncmp(st_info->instru, "pb\n", len_instru)))
		|| (!(ft_strncmp(st_info->last, "pb\n", len_last))
			&& !(ft_strncmp(st_info->instru, "pa\n", len_instru)))
		|| (!(ft_strncmp(st_info->last, "ra\n", len_last))
			&& !(ft_strncmp(st_info->instru, "rra\n", len_instru)))
		|| (!(ft_strncmp(st_info->last, "rra\n", len_last))
			&& !(ft_strncmp(st_info->instru, "ra\n", len_instru)))
		|| (!(ft_strncmp(st_info->last, "rb\n", len_last))
			&& !(ft_strncmp(st_info->instru, "rrb\n", len_instru)))
		|| (!(ft_strncmp(st_info->last, "rrb\n", len_last))
			&& !(ft_strncmp(st_info->instru, "rb\n", len_instru))))
		put_instru(st_info, "\0");
}

void	print_op1(t_info *st_info, int len_last, int len_instru)
{
	if (!(ft_strncmp(st_info->last, "sa\n", len_last))
		&& !(ft_strncmp(st_info->instru, "sb\n", len_instru)))
		put_instru(st_info, "ss\n");
	else if (!(ft_strncmp(st_info->last, "sb\n", len_last))
		&& !(ft_strncmp(st_info->instru, "sa\n", len_instru)))
		put_instru(st_info, "ss\n");
	else if (!(ft_strncmp(st_info->last, "ra\n", len_last))
		&& !(ft_strncmp(st_info->instru, "rb\n", len_instru)))
		put_instru(st_info, "rr\n");
	else if (!(ft_strncmp(st_info->last, "rb\n", len_last))
		&& !(ft_strncmp(st_info->instru, "ra\n", len_instru)))
		put_instru(st_info, "rr\n");
	else if (!(ft_strncmp(st_info->last, "rra\n", len_last))
		&& !(ft_strncmp(st_info->instru, "rrb\n", len_instru)))
		put_instru(st_info, "rrr\n");
	else if (!(ft_strncmp(st_info->last, "rrb\n", len_last))
		&& !(ft_strncmp(st_info->instru, "rra\n", len_instru)))
		put_instru(st_info, "rrr\n");
	print_null(st_info, len_last, len_instru);
}

void	print_operation(t_info *st_info)
{
	int	len_last;
	int	len_instru;

	if (!st_info->last || !st_info->instru)
	{
		if (!st_info->last)
			st_info->last = ft_strdup(st_info->instru);
		return ;
	}
	len_last = ft_strlen(st_info->last);
	len_instru = ft_strlen(st_info->instru);
	print_op1(st_info, len_last, len_instru);
	ft_putstr_fd(st_info->last, 1);
	free(st_info->last);
	st_info->last = NULL;
	if (st_info->instru)
	{
		st_info->last = ft_strdup(st_info->instru);
		free(st_info->instru);
		st_info->instru = NULL;
	}
}

void	free_elem(t_info *st_info)
{
	while (st_info->st_a->count)
		pop(st_info->st_a);
	while (st_info->st_b->count)
		pop(st_info->st_b);
	free(st_info->st_a);
	st_info->st_a = NULL;
	free(st_info->st_b);
	st_info->st_b = NULL;
	free(st_info->last);
	st_info->last = NULL;
	free(st_info);
	st_info = NULL;
}
