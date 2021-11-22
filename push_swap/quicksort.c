/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 10:53:06 by yang              #+#    #+#             */
/*   Updated: 2021/11/22 23:02:37 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	quicksort(t_stack *head_ref, t_info *st_info, int size, int sort_num)
{
	int	half_len;
	int	a;
	int	b;

	if (size <= 3)
	{
		//printf("sorting\n");
		init_sort(head_ref, st_info, size, sort_num);
		sort_stack(head_ref, st_info, st_info->a, st_info->b);
		return ;
	}
	half_len = partition(head_ref, size, st_info);
	if (head_ref != st_info->st_a)
	{
		a = half_len;
		b = size - half_len;
	}
	else
	{
		a = size - half_len;
		b = half_len;
	}
	quicksort(st_info->st_a, st_info, a, b);
	if (a > 3)
		a = 0;
	//printf("******** quicksort b *******\n");
	quicksort(st_info->st_b, st_info, b, a);
}
