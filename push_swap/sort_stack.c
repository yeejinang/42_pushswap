/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 09:05:15 by yang              #+#    #+#             */
/*   Updated: 2021/11/18 09:46:05 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *head_Ref, t_info *st_info, int a, int b)
{
	/*if (head_Ref == st_info->stack_a)
		st_info->sorted_b = true;*/
	if (a == 0 && b == 0)
	{
		sort_a(st_info);
		return ;
	}
	if (a == 3 && b == 0)
	{
		printf("sorting a3 b0\n");
		sort_a3_b0(st_info);
	}
	else if (a == 0 && b == 3)
	{
		printf("sorting a0 b3\n");
		sort_a0_b3(st_info);
	}
	else if (a == 2 && b == 2)
	{
		printf("sorting a2 b2\n");
		sort_a2_b2(st_info);
	}
	else if (a == 3 && b == 2)
	{
		printf("sorting a3 b2\n");
		sort_a3_b2(st_info);
	}
	else if (a == 2 && b == 3)
	{
		printf("sorting a2 b3\n");
		sort_a2_b3(st_info);
	}
	else
	{
		printf("sorting a3 b3\n");
		sort_ab3(st_info);
	}
	if (head_Ref == st_info->st_b)
	{
		while (b > 0)
		{
			push(st_info->st_a, st_info->st_b, 'a');
			b--;
		}
	}
	//st_info->sorted_b = true;
	st_info->st_a->sort_num = 0;
	st_info->st_a->rotate_count = 0;
}
