/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:04:49 by yang              #+#    #+#             */
/*   Updated: 2021/11/25 14:02:45 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*initialize_stack(t_stack *stack)
{
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->count = 0;
	stack->sort_num = 0;
	stack->rotate_count = 0;
	stack->tail = NULL;
	return (stack);
}

t_info	*initialize_info(t_info *st_info)
{
	st_info = (t_info *)malloc(sizeof(t_info));
	st_info->st_a = NULL;
	st_info->st_b = NULL;
	st_info->half_len = 0;
	st_info->first_round = true;
	st_info->last_round = false;
	st_info->total = 0;
	ft_bzero(st_info->last, 5);
	ft_bzero(st_info->instru, 5);
	return (st_info);
}

t_node	*lstnew(int content)
{
	t_node	*ptr;

	ptr = (t_node *)malloc(sizeof(t_node));
	if (ptr == NULL)
		return (NULL);
	ptr->prev = NULL;
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

void	addfront(t_stack *stack, t_node *new)
{
	t_node	*tail;

	tail = stack->tail;
	if (!tail)
	{
		tail = new;
		tail->prev = new;
		tail->next = new;
	}
	else
	{
		new->prev = tail;
		new->next = tail->next;
		tail->next->prev = new;
		tail->next = new;
	}
	stack->tail = tail;
	stack->count++;
}

void	free_elem(t_info *st_info)
{
	while (st_info->st_a->count)
		pop(st_info->st_a);
	free(st_info->st_a);
	free(st_info->st_b);
	free(st_info);
}

/*void	parse_arg(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_info	*st_info;

	stack_a = NULL;
	stack_b = NULL;
	st_info = NULL;
	stack_a = initialize_stack(stack_a);
	stack_b = initialize_stack(stack_b);
	st_info = initialize_info(st_info);
	stack_a = add_list(argc, argv, stack_a);
	st_info->st_a = stack_a;
	st_info->st_b = stack_b;
	st_info->total = st_info->st_a->count;
	quicksort(st_info->st_a, st_info, st_info->st_a->count, 0);
	free(stack_a);
	free(stack_b);
	free(st_info);
}

int main(int argc, char* argv[])
{
	if (argc > 1)
		parse_arg(argc, argv);
}*/