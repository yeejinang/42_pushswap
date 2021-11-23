/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:04:49 by yang              #+#    #+#             */
/*   Updated: 2021/11/23 18:44:22 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static t_stack	*initialize_stack(t_stack *stack)
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

static t_info	*initialize_info(t_info *st_info)
{
	st_info = (t_info *)malloc(sizeof(t_info));
	st_info->st_a = NULL;
	st_info->st_b = NULL;
	st_info->half_len = 0;
	st_info->first_round = true;
	st_info->last_round = false;
	st_info->total = 0;
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

t_stack	*add_list(int argc, char *argv[], t_stack *stack_a)
{
	t_node	*new;
	char	**split;
	int		total;

	total = 0;
	split = NULL;
	while (--argc >= 1)
	{
		split = ft_split(argv[argc], ' ');
		total = count(argv[argc], ' ');
		while (--total >= 0)
		{
			check_args(stack_a, split[total]);
			new = lstnew(ft_atoi(split[total]));
			addfront(stack_a, new);
		}
	}
	return (stack_a);
}

void	parse_arg(int argc, char *argv[])
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

	//printf("argc: %d\n", argc);
	/*if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		parse_arg(count(argv[1], ' '), split, 'y');
	}
	else if (argc > 1)
		parse_arg(argc, argv, 'n');*/

	if (argc > 1)
		parse_arg(argc, argv);
}