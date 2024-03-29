/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 09:05:15 by yang              #+#    #+#             */
/*   Updated: 2021/11/29 22:25:14 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sort(t_stack *head_ref, t_info *st_info, int size, int sort_num)
{
	st_info->st_a->rotate_count = 0;
	st_info->st_b->rotate_count = 0;
	if (head_ref == st_info->st_a)
	{
		st_info->a = size;
		st_info->b = sort_num;
	}
	else
	{
		st_info->a = sort_num;
		st_info->b = size;
	}
}

void	sort_stack(t_stack *head_ref, t_info *st_info, int a, int b)
{
	if (a == 0 && b == 0)
		sort_a3_b0(st_info);
	if (a == 3 && b == 0)
		sort_a3_b0(st_info);
	else if (a == 0 && b == 3)
		sort_a0_b3(st_info);
	else if (a == 2 && b == 2)
		sort_a2_b2(st_info);
	else if (a == 3 && b == 2)
		sort_a3_b2(st_info);
	else
		sort_a3_b3(st_info);
	if (head_ref == st_info->st_b)
	{
		while (b > 0)
		{
			push(st_info->st_a, st_info->st_b, 'a', st_info);
			b--;
		}
	}
}

int	check_reverse(t_stack *st_a)
{
	t_node	*temp;

	temp = st_a->tail->next;
	while (temp != st_a->tail)
	{
		if (temp->content < temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}
