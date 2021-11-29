/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:57:15 by yang              #+#    #+#             */
/*   Updated: 2021/11/29 21:32:32 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a2(t_info *st_info)
{
	t_node	*temp_a;

	temp_a = st_info->st_a->tail->next;
	if (temp_a->content > temp_a->next->content)
		swap(st_info->st_a, 'a', st_info);
}

void	sort_b2(t_info *st_info)
{
	t_node	*temp_b;

	temp_b = st_info->st_b->tail->next;
	if (temp_b->content < temp_b->next->content)
		swap(st_info->st_b, 'b', st_info);
}

void	sort_a2_b2(t_info *st_info)
{
	sort_a2(st_info);
	sort_b2(st_info);
}

void	sort_a3_b0(t_info *st_info)
{
	t_node	*temp_a;

	temp_a = st_info->st_a->tail->next;
	if (st_info->st_a->count <= 3)
	{
		while (!((temp_a->content < temp_a->next->content)
				&& (temp_a->next->content < temp_a->next->next->content)))
		{
			sort_a(st_info);
			temp_a = st_info->st_a->tail->next;
		}
	}
	else
	{
		while (st_info->st_a->rotate_count
			|| !((temp_a->content < temp_a->next->content)
				&& temp_a->next->content < temp_a->next->next->content))
		{
			sort_rotate_a(st_info);
			temp_a = st_info->st_a->tail->next;
		}
	}
}

void	sort_a0_b3(t_info *st_info)
{
	t_node	*temp_b;

	temp_b = st_info->st_b->tail->next;
	if (st_info->st_b->count <= 3)
	{
		while (!((temp_b->content > temp_b->next->content)
				&& (temp_b->next->content > temp_b->next->next->content)))
		{
			sort_b(st_info);
			temp_b = st_info->st_b->tail->next;
		}
	}
	else
	{
		while (st_info->st_b->rotate_count
			|| !((temp_b->content > temp_b->next->content)
				&& temp_b->next->content > temp_b->next->next->content))
		{
			sort_rotate_b(st_info);
			temp_b = st_info->st_b->tail->next;
		}
	}
}
