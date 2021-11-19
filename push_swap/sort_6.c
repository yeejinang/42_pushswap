/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:05:40 by yang              #+#    #+#             */
/*   Updated: 2021/11/16 15:39:38 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_ab3_1(t_info *st_info)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = st_info->st_a->tail->next;
	temp_b = st_info->st_b->tail->next;
	rotate(st_info->st_a, ' ');
	if (temp_b->content < temp_b->prev->content
		&& temp_b->content < temp_b->next->content)
		rotate(st_info->st_b, 'c');
	else
	{
		write(1, "ra\n", 3);
		if (temp_b->content < temp_b->next->content)
			swap(st_info->st_b, 'b');
		else
			reverse_rotate(st_info->st_b, 'b');
	}
}

void	sort_ab3_2(t_info *st_info)
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
		if (temp_b->content < temp_b->prev->content
			&& temp_b->content < temp_b->next->content)
			rotate(st_info->st_b, 'b');
		else
			reverse_rotate(st_info->st_b, 'b');
	}
}

void	sort_ab3_3(t_info *st_info)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = st_info->st_a->tail->next;
	temp_b = st_info->st_b->tail->next;
	reverse_rotate(st_info->st_a, ' ');
	if (temp_b->content < temp_b->prev->content
		&& temp_b->content < temp_b->next->content)
	{
		write(1, "rra\n", 4);
		rotate(st_info->st_b, 'b');
	}
	else if (temp_b->content < temp_b->next->content)
	{
		write(1, "rra\n", 4);
		swap(st_info->st_b, 'c');
	}
	else
		reverse_rotate(st_info->st_b, 'c');
}

void	sort_ab3(t_info *st_info)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = st_info->st_a->tail->next;
	temp_b = st_info->st_b->tail->next;
	while (!(temp_a->content < temp_a->next->content
			&& temp_a->next->content < temp_a->prev->content)
		|| !(temp_b->content > temp_b->next->content
			&& temp_b->content > temp_b->prev->content))
	{
		if (temp_a->content > temp_a->prev->content
			&& temp_a->content > temp_a->next->content)
			sort_ab3_1(st_info);
		else if (temp_a->content > temp_a->next->content)
			sort_ab3_2(st_info);
		else
			sort_ab3_3(st_info);
		temp_a = st_info->st_a->tail->next;
		temp_b = st_info->st_b->tail->next;
	}
}
