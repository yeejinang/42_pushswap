/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:24:33 by yang              #+#    #+#             */
/*   Updated: 2021/11/30 14:15:48 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_instruction(t_info *st_info, char **line)
{
	int	ret;

	ret = get_next_line(1, line);
	while (ret > 0)
	{
		if (!process_swap(st_info, *line) && !process_push(st_info, *line)
			&& !process_rotate(st_info, *line)
			&& !process_reverse(st_info, *line))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		ret = get_next_line(1, line);
	}
	if (ret == 0)
	{
		if (check_sorted(st_info->st_a) && !st_info->st_b->count)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	return (*line);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_info	*st_info;
	char	**line;

	stack_a = NULL;
	stack_b = NULL;
	st_info = NULL;
	line = NULL;
	line = (char **)malloc(sizeof(char *));
	stack_a = initialize_stack(stack_a);
	stack_b = initialize_stack(stack_b);
	st_info = initialize_info(st_info);
	stack_a = add_list(argc, argv, stack_a);
	st_info->st_a = stack_a;
	st_info->st_b = stack_b;
	get_instruction(st_info, line);
	free(line);
	free_elem(st_info);
	return (0);
}
