/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:44:51 by yang              #+#    #+#             */
/*   Updated: 2021/11/29 22:23:13 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition_a(t_info *st_info, int size)
{
	int		pivot;
	t_node	*temp_a;

	pivot = get_median(st_info->st_a, size);
	while (st_info->half_len < (size / 2))
	{
		temp_a = st_info->st_a->tail;
		temp_a = temp_a->next;
		if (temp_a->content < pivot)
		{
			push(st_info->st_b, st_info->st_a, 'b', st_info);
			st_info->half_len++;
		}
		else if (check_reverse(st_info->st_a) && size >= 6)
			reverse_rotate(st_info->st_a, 'a', st_info);
		else
			rotate(st_info->st_a, 'a', st_info);
	}
	return (st_info->half_len);
}

static int	partition_b(t_info *st_info, int size)
{
	int		pivot;
	t_node	*temp_b;

	pivot = get_median(st_info->st_b, size);
	while (st_info->half_len < ((size / 2) + (size % 2)))
	{
		temp_b = st_info->st_b->tail;
		temp_b = temp_b->next;
		if (temp_b->content >= pivot)
		{
			push(st_info->st_a, st_info->st_b, 'a', st_info);
			st_info->half_len++;
		}
		else
			rotate(st_info->st_b, 'b', st_info);
	}
	return (st_info->half_len);
}

int	partition(t_stack *head_ref, int size, t_info *st_info)
{
	int	half_len;

	st_info->half_len = 0;
	if (head_ref == st_info->st_a)
		half_len = partition_a(st_info, size);
	else
		half_len = partition_b(st_info, size);
	while (head_ref->count != (size - half_len) && head_ref->rotate_count)
	{
		if (head_ref == st_info->st_a)
			reverse_rotate(head_ref, 'a', st_info);
		else
			reverse_rotate(head_ref, 'b', st_info);
	}
	return (half_len);
}
