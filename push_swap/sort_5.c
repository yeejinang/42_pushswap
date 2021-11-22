/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:13:46 by yang              #+#    #+#             */
/*   Updated: 2021/11/22 22:30:44 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_rotate_b1(t_info *st_info)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = st_info->st_a->tail->next;
	temp_b = st_info->st_b->tail->next;
	rotate(st_info->st_a, ' ');
	if (!st_info->st_b->rotate_count && temp_b->content > temp_b->next->content)
		rotate(st_info->st_b, 'c');
	else
	{
		write(1, "ra\n", 3);
		if (temp_b->content < temp_b->next->content)
			swap(st_info->st_b, 'b');
		else if (st_info->st_b->rotate_count)
			reverse_rotate(st_info->st_b, 'b');
	}
}

static void	sort_rotate_b2(t_info *st_info)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = st_info->st_a->tail->next;
	temp_b = st_info->st_b->tail->next;
	swap(st_info->st_a, ' ');
	if (temp_b->content < temp_b->next->content)
		swap(st_info->st_b, 'c');
	else
	{
		write(1, "sa\n", 3);
		if (!st_info->st_b->rotate_count
			&& temp_b->content > temp_b->next->content)
			rotate(st_info->st_b, 'b');
		else if (st_info->st_b->rotate_count)
			reverse_rotate(st_info->st_b, 'b');
	}
}

static void	sort_rotate_b3(t_info *st_info)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = st_info->st_a->tail->next;
	temp_b = st_info->st_b->tail->next;
	reverse_rotate(st_info->st_a, ' ');
	if (st_info->st_b->rotate_count && temp_b->content > temp_b->next->content)
		reverse_rotate(st_info->st_b, 'c');
	else
	{
		write(1, "rra\n", 4);
		if (!st_info->st_b->rotate_count
			&& temp_b->content > temp_b->next->content)
			rotate(st_info->st_b, 'b');
		else if (temp_b->content < temp_b->next->content)
			swap(st_info->st_b, 'b');
	}
}

void	sort_check(t_info *st_info)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = st_info->st_a->tail->next;
	temp_b = st_info->st_b->tail->next;
	if (!st_info->st_a->rotate_count && temp_a->content < temp_a->next->content
		&& temp_a->next->content < temp_a->next->next->content)
		sort_rotate_b(st_info);
	else if ((!st_info->st_b->rotate_count
			&& temp_b->content > temp_b->next->content
			&& temp_b->next->content > temp_b->next->next->content))
		sort_rotate_a(st_info);
}

void	sort_rotate(t_info *st_info)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = st_info->st_a->tail->next;
	temp_b = st_info->st_b->tail->next;
	while (st_info->st_a->rotate_count || st_info->st_b->rotate_count
		|| !(temp_a->content < temp_a->next->content
			&& temp_a->next->content < temp_a->next->next->content)
		|| !(temp_b->content > temp_b->next->content
			&& temp_b->next->content > temp_b->next->next->content))
	{
		sort_check(st_info);
		if (!st_info->st_a->rotate_count
			&& temp_a->content < temp_a->next->content)
			sort_rotate_b1(st_info);
		else if (temp_a->content > temp_a->next->content)
			sort_rotate_b2(st_info);
		else if (st_info->st_a->rotate_count
			&& temp_a->content < temp_a->next->content)
			sort_rotate_b3(st_info);
		temp_a = st_info->st_a->tail->next;
		temp_b = st_info->st_b->tail->next;
	}
}
