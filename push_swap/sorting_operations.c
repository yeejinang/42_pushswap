/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:10:44 by yang              #+#    #+#             */
/*   Updated: 2021/11/25 16:16:42 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop(t_stack *stack)
{
	t_node	*temp;

	temp = stack->tail->next;
	if (stack->count == 2)
	{
		stack->tail->next = stack->tail;
		stack->tail->prev = stack->tail;
	}
	else if (stack->count == 3)
	{
		stack->tail->next = stack->tail->prev;
		stack->tail->prev->prev = stack->tail;
	}
	else if (stack->count > 3)
	{
		stack->tail->next = stack->tail->next->next;
		stack->tail->next->prev = stack->tail;
	}
	free(temp);
	temp = NULL;
	stack->count--;
}

void	swap(t_stack *stack, char print, t_info *st_info)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (stack->count <= 1)
		return ;
	first = stack->tail->next;
	second = first->next;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
	if (print == 'a')
		ft_strlcpy(st_info->instru, "sa\n", 4);
	else if (print == 'b')
		ft_strlcpy(st_info->instru, "sb\n", 4);
}

void	push(t_stack *st_push, t_stack *st_pop, char print, t_info *st_info)
{
	t_node	*new;

	if (st_pop->count == 0)
		return ;
	new = lstnew(st_pop->tail->next->content);
	addfront(st_push, new);
	pop(st_pop);
	if (print == 'a')
		ft_strlcpy(st_info->instru, "pa\n", 4);
	else if (print == 'b')
		ft_strlcpy(st_info->instru, "pb\n", 4);
}

void	rotate(t_stack *stack, char print, t_info *st_info)
{
	if (stack->count <= 1)
		return ;
	stack->tail = stack->tail->next;
	stack->rotate_count++;
	if (print == 'a')
		ft_strlcpy(st_info->instru, "ra\n", 4);
	else if (print == 'b')
		ft_strlcpy(st_info->instru, "rb\n", 4);
}

void	reverse_rotate(t_stack *stack, char print, t_info *st_info)
{
	if (stack->count <= 1)
		return ;
	stack->tail = stack->tail->prev;
	stack->rotate_count--;
	if (print == 'a')
		ft_strlcpy(st_info->instru, "rra\n", 4);
	else if (print == 'b')
		ft_strlcpy(st_info->instru, "rrb\n", 4);
}
