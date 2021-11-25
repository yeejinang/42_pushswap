/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 10:53:06 by yang              #+#    #+#             */
/*   Updated: 2021/11/25 15:05:36 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	quicksort(t_stack *head_ref, t_info *st_info, int size, int sort_num)
{
	int	half_len;
	int	a;
	int	b;

	if (size <= 3)
	{
		//printf("sorting\n");
		init_sort(head_ref, st_info, size, sort_num);
		sort_stack(head_ref, st_info, st_info->a, st_info->b);
		return ;
	}
	half_len = partition(head_ref, size, st_info);
	if (head_ref != st_info->st_a)
	{
		a = half_len;
		b = size - half_len;
	}
	else
	{
		a = size - half_len;
		b = half_len;
	}
	quicksort(st_info->st_a, st_info, a, b);
	if (a > 3)
		a = 0;
	//printf("******** quicksort b *******\n");
	quicksort(st_info->st_b, st_info, b, a);
}

/*t_stack	*add_list(int argc, char *argv[], t_stack *stack_a)
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
}*/

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
	//ft_putstr_fd(st_info->instru, 1);
	free_elem(st_info);
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