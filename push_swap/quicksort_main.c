/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:31:50 by yang              #+#    #+#             */
/*   Updated: 2021/11/24 15:33:04 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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