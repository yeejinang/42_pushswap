/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:44:51 by yang              #+#    #+#             */
/*   Updated: 2021/11/25 16:15:20 by yang             ###   ########.fr       */
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
			push(st_info->st_b, st_info->st_a, 'b', st_info);
			st_info->half_len++;
		}
		else
			rotate(st_info->st_a, 'a', st_info);
		print_operation(st_info);
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
		print_operation(st_info);
	}
	return (st_info->half_len);
}

int	partition(t_stack *head_ref, int size, t_info *st_info)
{
	int	half_len;

	st_info->half_len = 0;
	//printf("partitioning........... \n");
	int i;

	i = 0;
	/*t_node *temp_a = head_ref->tail->next;
	do
	{
		printf("prev: %p\t add: %p\t content: %d\t next: %p\n", temp_a->prev, temp_a, temp_a->content, temp_a->next);
		temp_a = temp_a->next;
	} while (temp_a != head_ref->tail->next && i++ <= size);*/

	if (head_ref == st_info->st_b && size == (st_info->total / 2))
	{
		//printf("setting last round..... \n");
		st_info->last_round = true;
	}
	if (head_ref == st_info->st_a)
		half_len = partition_a(st_info, size); //refer to how many numbers were pushed to stack B
	else
		half_len = partition_b(st_info, size); //refer to how many numbers were pushed to stack A
	while (!st_info->first_round && head_ref->count != size && head_ref->rotate_count)
	{
		//printf("reverse rotate stack\n");
		if (head_ref == st_info->st_a)
			reverse_rotate(head_ref, 'a', st_info);
		else
			reverse_rotate(head_ref, 'b', st_info);
		print_operation(st_info);
	}
	return (half_len);
}
