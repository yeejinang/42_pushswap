/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:04:49 by yang              #+#    #+#             */
/*   Updated: 2021/11/29 20:19:08 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	st_info->total = 0;
	st_info->last = NULL;
	st_info->instru = NULL;
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
			free(split[total]);
		}
		free(split);
	}
	return (stack_a);
}
