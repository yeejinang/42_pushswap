/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:10:44 by yang              #+#    #+#             */
/*   Updated: 2021/11/30 14:03:22 by yang             ###   ########.fr       */
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
	if (st_info->instru)
		free(st_info->instru);
	if (print == 'a')
		st_info->instru = ft_strdup("sa\n");
	else if (print == 'b')
		st_info->instru = ft_strdup("sb\n");
	if (print != ' ')
		print_operation(st_info);
}

void	push(t_stack *st_push, t_stack *st_pop, char print, t_info *st_info)
{
	t_node	*new;

	if (st_pop->count == 0)
		return ;
	new = lstnew(st_pop->tail->next->content);
	addfront(st_push, new);
	pop(st_pop);
	if (st_info->instru)
		free(st_info->instru);
	if (print == 'a')
		st_info->instru = ft_strdup("pa\n");
	else if (print == 'b')
		st_info->instru = ft_strdup("pb\n");
	if (print != ' ')
		print_operation(st_info);
}

void	rotate(t_stack *stack, char print, t_info *st_info)
{
	if (stack->count <= 1)
		return ;
	stack->tail = stack->tail->next;
	stack->rotate_count++;
	if (st_info->instru)
		free(st_info->instru);
	if (print == 'a')
		st_info->instru = ft_strdup("ra\n");
	else if (print == 'b')
		st_info->instru = ft_strdup("rb\n");
	if (print != ' ')
		print_operation(st_info);
}

void	reverse_rotate(t_stack *stack, char print, t_info *st_info)
{
	if (stack->count <= 1)
		return ;
	stack->tail = stack->tail->prev;
	stack->rotate_count--;
	if (st_info->instru)
		free(st_info->instru);
	if (print == 'a')
		st_info->instru = ft_strdup("rra\n");
	else if (print == 'b')
		st_info->instru = ft_strdup("rrb\n");
	if (print != ' ')
		print_operation(st_info);
}
