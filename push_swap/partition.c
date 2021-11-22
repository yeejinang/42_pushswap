/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:44:51 by yang              #+#    #+#             */
/*   Updated: 2021/11/22 15:56:21 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static void	numbers_a(t_info *st_info, int size)
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
}*/

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
			push(st_info->st_b, st_info->st_a, 'b');
			st_info->half_len++;
		}
		else
			rotate(st_info->st_a, 'a');
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
			push(st_info->st_a, st_info->st_b, 'a');
			st_info->half_len++;
		}
		else
			rotate(st_info->st_b, 'b');
	}
	return (st_info->half_len);
}

int	partition(t_stack *head_Ref, int size, t_info *st_info)
{
	int	half_len;

	st_info->half_len = 0;
	printf("go into partition\n");
	if (head_Ref == st_info->st_a)
		half_len = partition_a(st_info, size); //refer to how many numbers were pushed to stack B
	else
		half_len = partition_b(st_info, size); //refer to how many numbers were pushed to stack A
	while (!st_info->first_round && head_Ref->rotate_count)
	{
		if (head_Ref == st_info->st_a)
			reverse_rotate(head_Ref, 'a');
		else
			reverse_rotate(head_Ref, 'b');
	}
	printf("done partition\n");
	return (half_len);
}
