/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 08:29:10 by yang              #+#    #+#             */
/*   Updated: 2021/11/22 14:11:26 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a3_b2_1(t_info *st_info)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = st_info->st_a->tail->next;
	temp_b = st_info->st_b->tail->next;
	while (!(temp_a->content < temp_a->next->content
			&& temp_a->next->content < temp_a->prev->content))
	{
		if (temp_a->content > temp_a->prev->content
			&& temp_a->content > temp_a->next->content)
			rotate(st_info->st_a, 'a');
		else if (temp_a->content > temp_a->next->content)
		{
			swap(st_info->st_a, ' ');
			if (temp_b->content < temp_b->next->content)
				swap(st_info->st_b, 'c');
			else
				write(1, "sa\n", 3);
		}
		else
			reverse_rotate(st_info->st_a, 'a');
		temp_a = st_info->st_a->tail->next;
		temp_b = st_info->st_b->tail->next;
	}
}

static void	sort_a3_b2_2(t_info *st_info)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = st_info->st_a->tail->next;
	temp_b = st_info->st_b->tail->next;
	if (!st_info->st_a->rotate_count && temp_a->content < temp_a->next->content)
		rotate(st_info->st_a, 'a');
	else if (temp_a->content > temp_a->next->content)
	{
		swap(st_info->st_a, ' ');
		if (temp_b->content < temp_b->next->content)
			swap(st_info->st_b, 'c');
		else
			write(1, "sa\n", 3);
	}
	else if (st_info->st_a->rotate_count
		&& temp_a->content < temp_a->next->content)
		reverse_rotate(st_info->st_a, 'a');
}

void	sort_a3_b2(t_info *st_info)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = st_info->st_a->tail->next;
	temp_b = st_info->st_b->tail->next;
	if (st_info->st_a->count <= 3)
		sort_a3_b2_1(st_info);
	else
	{
		while (st_info->st_a->rotate_count
			|| !(temp_a->content < temp_a->next->content
				&& temp_a->next->content < temp_a->next->next->content))
		{
			sort_a3_b2_2(st_info);
			temp_a = st_info->st_a->tail->next;
		}
	}
	if (temp_b->content < temp_b->next->content)
		swap(st_info->st_b, 'b');
}
