/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 08:41:17 by yang              #+#    #+#             */
/*   Updated: 2021/11/16 15:38:41 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a2_b3_1(t_info *st_info)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = st_info->st_a->tail->next;
	temp_b = st_info->st_b->tail->next;
	if (temp_b->content < temp_b->prev->content
		&& temp_b->content < temp_b->next->content)
		rotate(st_info->st_b, 'b');
	else if (temp_b->content < temp_b->next->content)
	{
		swap(st_info->st_b, ' ');
		if (temp_a->content > temp_a->next->content)
			swap(st_info->st_a, 'c');
		else
			write(1, "sb\n", 3);
	}
	else
		reverse_rotate(st_info->st_b, 'b');
}

static void	sort_a2_b3_2(t_info *st_info)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = st_info->st_a->tail->next;
	temp_b = st_info->st_b->tail->next;
	if (!st_info->st_b->rotate_count && temp_b->content < temp_b->next->content)
		rotate(st_info->st_b, 'b');
	else if (temp_b->content > temp_b->next->content)
	{
		swap(st_info->st_b, ' ');
		if (temp_a->content > temp_a->next->content)
			swap(st_info->st_a, 'c');
		else
			write(1, "sb\n", 3);
	}
	else if (st_info->st_b->rotate_count && temp_b->content < temp_b->next->content)
		reverse_rotate(st_info->st_b, 'b');
}

void	sort_a2_b3(t_info *st_info)
{
	t_node	*temp_b;

	temp_b = st_info->st_b->tail->next;
	if (st_info->st_b->count <= 3)
	{
		while (!(temp_b->content > temp_b->next->content
				&& temp_b->content > temp_b->prev->content))
		{
			sort_a2_b3_1(st_info);
			temp_b = st_info->st_b->tail->next;
		}
	}
	else
	{
		while (st_info->st_b->rotate_count
			|| !(temp_b->content < temp_b->next->content
				&& temp_b->next->content < temp_b->next->next->content))
		{
			sort_a2_b3_2(st_info);
			temp_b = st_info->st_b->tail->next;
		}
	}
}
