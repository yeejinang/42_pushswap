/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:01:05 by yang              #+#    #+#             */
/*   Updated: 2021/11/25 09:33:41 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a3_b0(t_info *st_info)
{
	if (st_info->st_a->count <= 3)
		sort_a(st_info);
	else
		sort_rotate_a(st_info);
}

void	sort_a0_b3(t_info *st_info)
{	
	if (st_info->st_b->count <= 3)
		sort_b(st_info);
	else
		sort_rotate_b(st_info);
}

void	sort_a2_b2(t_info *st_info)
{
	t_node	*temp_a;
	t_node	*temp_b;

	temp_a = st_info->st_a->tail->next;
	temp_b = st_info->st_b->tail->next;
	//printf("stack_a first: %d\t second: %d\n", temp_a->content, temp_a->next->content);
	//printf("stack_b first: %d\t second: %d\n", temp_b->content, temp_b->next->content);
	if (temp_a->content > temp_a->next->content)
	{
		swap(st_info->st_a, ' ');
		if (temp_b->content < temp_b->next->content)
			swap(st_info->st_b, 'c');
		else
			write(1, "sa\n", 3);
	}
	else if (temp_b->content < temp_b->next->content)
		swap(st_info->st_b, 'b');
}

void	sort_a3_b3(t_info *st_info)
{
	if (st_info->st_a->count <= 3)
	{
		if (st_info->st_b->count <= 3)
			sort_ab3(st_info);
		else if (st_info->st_b->count > 3)
		{
			sort_a(st_info);
			sort_rotate_b(st_info);
		}
	}
	else
	{
		if (st_info->st_b->count <= 3)
		{
			sort_rotate_a(st_info);
			sort_b(st_info);
		}
		else 
			sort_rotate(st_info);
	}
}
