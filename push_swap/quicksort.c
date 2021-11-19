/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 10:53:06 by yang              #+#    #+#             */
/*   Updated: 2021/11/18 10:20:43 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	quickSort(t_stack *head_Ref, int size, t_info *st_info, int sort_num)
{
	int	half_len;
	int	a;
	int b;
	
	st_info->half_len = 0;
	a = 0;
	b = 0;
	if (size <= 3)
	{
		st_info->first_round = false;
		//sort_a(st_info);
		/*if (st_info->sorted_b && st_info->st_a->sort_num == 0)
			return ;*/
		if (head_Ref == st_info->st_a)
		{
			a = size;
			b = sort_num;
		}
		else
		{
			a = sort_num;
			b = size;
		}
		printf("sort_num a: %d\t sort_num b: %d\n", a, b);
		//printf("sorting num a: %d\t b: %d\n", st_info->st_b->sort_num, st_info->st_b->sort_num);
		//if (a || b)
		sort_stack(head_Ref, st_info, a, b);
		//else
			//sort_a(st_info);
		return ;
	}
	/* half_len refer to how many numbers were pushed to another stack */
	half_len = partition(head_Ref, size, st_info);
	while (!st_info->first_round && head_Ref->rotate_count)
	{
		if (head_Ref == st_info->st_a)
			reverse_rotate(head_Ref, 'a');
		else
			reverse_rotate(head_Ref, 'b');
	}
	if (st_info->first_round)
		st_info->st_a->rotate_count = 0;
	printf("after partition: rotate count st_a: %d\t st_b: %d\n", st_info->st_a->rotate_count, st_info->st_b->rotate_count);
	/*recursively call for stack a*/

	//printf("stack b: %p\t tail: %p\n", st_info->stack_b, *st_info->stack_b);
	printf("size: %d\t half_len: %d\n", size-half_len, half_len);
	printf("\n******* quicksort A ********\n");
	/*if (head_Ref != st_info->st_a)
	{
		a = half_len;
		b = size - half_len;
	}
	else
	{
		a = size - half_len;
		b = half_len;
	}*/
	quickSort(st_info->st_a, size - half_len, st_info, half_len);
	printf("size: %d\t half_len: %d\n", size-half_len, half_len);
	/*recursively call for stack b*/
	/*if the head Ref is stack a, then the half len for st b should be half_len*/
	/*if (head_Ref != st_info->st_b)
	{
		a = size - half_len;
		b = half_len;
	}
	else
	{
		a = half_len;
		b = size - half_len;
	}*/
	if (size - half_len > 3)
		a = 0;
	else
		a = size - half_len;
	printf("\n******* quicksort B ********\n");
	quickSort(st_info->st_b, half_len, st_info, a);
}


/*static void	numbers_b(t_info *st_info, int size)
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