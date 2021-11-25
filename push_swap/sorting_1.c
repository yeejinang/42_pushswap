/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:50:59 by yang              #+#    #+#             */
/*   Updated: 2021/11/25 13:50:55 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_info *st_info)
{
	t_node	*temp_a;

	temp_a = st_info->st_a->tail->next;
	if (!(temp_a->content < temp_a->next->content
			&& temp_a->next->content < temp_a->prev->content))
	{
		if (temp_a->content > temp_a->prev->content
			&& temp_a->content > temp_a->next->content)
			rotate(st_info->st_a, 'a', st_info);
		else if (temp_a->content > temp_a->next->content)
			swap(st_info->st_a, 'a', st_info);
		else
			reverse_rotate(st_info->st_a, 'a', st_info);
		print_operation(st_info);
	}
}

void	sort_b(t_info *st_info)
{
	t_node	*temp_b;

	temp_b = st_info->st_b->tail->next;
	if (!(temp_b->content > temp_b->next->content
			&& temp_b->content > temp_b->prev->content))
	{
		if (temp_b->content < temp_b->prev->content
			&& temp_b->content < temp_b->next->content)
			rotate(st_info->st_b, 'b', st_info);
		else if (temp_b->content < temp_b->next->content)
			swap(st_info->st_b, 'b', st_info);
		else
			reverse_rotate(st_info->st_b, 'b', st_info);
		print_operation(st_info);
	}
}

void	sort_rotate_a(t_info *st_info)
{
	t_node	*temp_a;

	temp_a = st_info->st_a->tail->next;
	if (st_info->st_a->rotate_count
		|| !(temp_a->content < temp_a->next->content
			&& temp_a->next->content < temp_a->next->next->content))
	{
		if (temp_a->content > temp_a->next->content)
			swap(st_info->st_a, 'a', st_info);
		else if (!st_info->st_a->rotate_count
			&& temp_a->content < temp_a->next->content)
			rotate(st_info->st_a, 'a', st_info);
		else if (st_info->st_a->rotate_count
			&& temp_a->content < temp_a->next->content)
			reverse_rotate(st_info->st_a, 'a', st_info);
		print_operation(st_info);
	}
}

void	sort_rotate_b(t_info *st_info)
{
	t_node	*temp_b;

	temp_b = st_info->st_b->tail->next;
	if (st_info->st_b->rotate_count
		|| !(temp_b->content > temp_b->next->content
			&& temp_b->next->content > temp_b->next->next->content))
	{
		if (temp_b->content < temp_b->next->content)
			swap(st_info->st_b, 'b', st_info);
		else if (!st_info->st_b->rotate_count
			&& temp_b->content > temp_b->next->content)
			rotate(st_info->st_b, 'b', st_info);
		else if (st_info->st_b->rotate_count
			&& temp_b->content > temp_b->next->content)
			reverse_rotate(st_info->st_b, 'b', st_info);
		print_operation(st_info);
	}
}
