/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:24:05 by yang              #+#    #+#             */
/*   Updated: 2021/11/29 22:25:04 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a3_b2_1(t_info *st_info)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = st_info->st_a->tail->next;
	temp_b = st_info->st_b->tail->next;
	while (!((temp_a->content < temp_a->next->content)
			&& (temp_a->next->content < temp_a->next->next->content))
		|| (temp_b->content < temp_b->next->content))
	{
		sort_a(st_info);
		sort_b2(st_info);
		temp_a = st_info->st_a->tail->next;
	}
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
			|| !((temp_a->content < temp_a->next->content)
				&& (temp_a->next->content < temp_a->next->next->content)
				&& (temp_b->content > temp_b->next->content)))
		{
			sort_rotate_a(st_info);
			sort_b2(st_info);
			temp_a = st_info->st_a->tail->next;
		}
	}
}

void	sort_b3(t_info *st_info)
{
	if (st_info->st_b->count <= 3)
		sort_b(st_info);
	else
		sort_rotate_b(st_info);
}

static void	sort_a3_b3_1(t_info *st_info)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = st_info->st_a->tail->next;
	temp_b = st_info->st_b->tail->next;
	while (!((temp_a->content < temp_a->next->content)
			&& (temp_a->next->content < temp_a->next->next->content))
		|| (!(temp_b->content > temp_b->next->content
				&& temp_b->next->content > temp_b->next->next->content)))
	{
		sort_a(st_info);
		sort_b3(st_info);
		temp_a = st_info->st_a->tail->next;
		temp_b = st_info->st_b->tail->next;
	}
}

void	sort_a3_b3(t_info *st_info)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = st_info->st_a->tail->next;
	temp_b = st_info->st_b->tail->next;
	if (st_info->st_a->count <= 3)
		sort_a3_b3_1(st_info);
	else
	{
		while (st_info->st_a->rotate_count || st_info->st_b->rotate_count
			|| !((temp_a->content < temp_a->next->content)
				&& (temp_a->next->content < temp_a->next->next->content)
				&& (temp_b->content > temp_b->next->content)
				&& (temp_b->next->content > temp_b->next->next->content)))
		{
			sort_rotate_a(st_info);
			sort_b3(st_info);
			temp_a = st_info->st_a->tail->next;
			temp_b = st_info->st_b->tail->next;
		}
	}
}
