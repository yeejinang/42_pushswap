/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 22:09:42 by yang              #+#    #+#             */
/*   Updated: 2021/11/22 13:50:02 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void	swap(t_stack *stack, char print)
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
		write(1, "sa\n", 3);
	else if (print == 'b')
		write(1, "sb\n", 3);
	else if (print == 'c')
		write (1, "ss\n", 3);
}

void	push(t_stack *st_push, t_stack *st_pop, char print)
{
	t_node	*new;

	if (st_pop->count == 0)
		return ;
	new = lstnew(st_pop->tail->next->content);
	addfront(st_push, new);
	pop(st_pop);
	if (print == 'a')
		write(1, "pa\n", 3);
	else if (print == 'b')
		write(1, "pb\n", 3);
}

void	rotate(t_stack *stack, char print)
{
	if (stack->count <= 1)
		return ;
	stack->tail = stack->tail->next;
	stack->rotate_count++;
	if (print == 'a')
		write(1, "ra\n", 3);
	else if (print == 'b')
		write(1, "rb\n", 3);
	else if (print == 'c')
		write (1, "rr\n", 3);
}

void	reverse_rotate(t_stack *stack, char print)
{
	if (stack->count <= 1)
		return ;
	stack->tail = stack->tail->prev;
	stack->rotate_count--;
	if (print == 'a')
		write(1, "rra\n", 4);
	else if (print == 'b')
		write(1, "rrb\n", 4);
	else if (print == 'c')
		write (1, "rrr\n", 4);
}
