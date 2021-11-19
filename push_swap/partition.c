/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:44:51 by yang              #+#    #+#             */
/*   Updated: 2021/11/18 09:48:35 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	numbers_a(t_info *st_info, int size)
{
	if (st_info->half_len <= 3)
	{
		st_info->st_a->sort_num = st_info->half_len;
		if (size - st_info->half_len <= 3)
			st_info->st_b->sort_num = size - st_info->half_len;
		else
			st_info->st_a->sort_num = 0;
	}
	else
		return ;
}

static void	numbers_b(t_info *st_info, int size)
{
	if (st_info->half_len <= 3)
	{
		st_info->st_b->sort_num = st_info->half_len;
		if (size - st_info->half_len <= 3)
			st_info->st_a->sort_num = size - st_info->half_len;
		else
			st_info->st_b->sort_num = 0;
	}
	else
		return ;
}

static int partition_a(t_info *st_info, int size)
{
	int		pivot;
	t_node	*temp_a;

	pivot = getMedian(st_info->st_a, size);
	printf("pivot: %d\n", pivot);
	while (st_info->half_len < (size / 2))
	{
		temp_a = st_info->st_a->tail;
		temp_a = temp_a->next;
		if (temp_a->content < pivot)
		{
			push(st_info->st_b, st_info->st_a, 'b');
			st_info->half_len++;
		}
		else
			rotate(st_info->st_a, 'a');
	}
	//st_info->st_a->rotate_count = 0;
	numbers_a(st_info, size);
	return (st_info->half_len);
}

static int partition_b(t_info *st_info, int size)
{
	int		pivot;
	t_node	*temp_b;

	pivot = getMedian(st_info->st_b, size);
	printf("pivot: %d\n", pivot);
	while (st_info->half_len <= (size / 2))
	{
		temp_b = st_info->st_b->tail;
		temp_b = temp_b->next;
		if (temp_b->content >= pivot)
		{
			push(st_info->st_a, st_info->st_b, 'a');
			st_info->half_len++;
		}
		else
			rotate(st_info->st_b, 'b');
	}
	numbers_b(st_info, size);
	//st_info->st_b->rotate_count = 0;
	printf("partition_b: rotate count a: %d\t rotate count b: %d\n", st_info->st_a->rotate_count, st_info->st_b->rotate_count);
	return (st_info->half_len);
}

int	partition(t_stack *head_Ref, int size, t_info *st_info)
{
	int	half_len;

	st_info->half_len = 0;
	if (head_Ref == st_info->st_a)
		half_len = partition_a(st_info, size);
	else
		half_len = partition_b(st_info, size);
	return (half_len);
}
