/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:24:33 by yang              #+#    #+#             */
/*   Updated: 2021/11/24 19:17:33 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_swap(t_info *st_info, char *line)
{
	if (ft_strncmp(line, "sa", 2) == 0)
	{
		swap(st_info->st_a, ' ');
		return (1);
	}
	else if (ft_strncmp(line, "sb", 2) == 0)
	{
		swap(st_info->st_b, ' ');
		return (1);
	}
	else if (ft_strncmp(line, "ss", 2) == 0)
	{
		swap(st_info->st_a, ' ');
		swap(st_info->st_b, ' ');
		return (1);
	}
	return (0);
}

int	process_push(t_info *st_info, char *line)
{
	if (ft_strncmp(line, "pa", 2) == 0)
	{
		push(st_info->st_a, st_info->st_b, ' ');
		return (1);
	}
	else if (ft_strncmp(line, "pb", 2) == 0)
	{
		push(st_info->st_b, st_info->st_a, ' ');
		return (1);
	}
	return (0);
}

int	process_rotate(t_info *st_info, char *line)
{
	if (ft_strncmp(line, "ra", 2) == 0)
	{
		rotate(st_info->st_a, ' ');
		return (1);
	}
	else if (ft_strncmp(line, "rb", 2) == 0)
	{
		rotate(st_info->st_b, ' ');
		return (1);
	}
	else if (ft_strncmp(line, "rr", 2) == 0)
	{
		rotate(st_info->st_a, ' ');
		rotate(st_info->st_b, ' ');
		return (1);
	}
	return (0);
}

int	process_reverse(t_info *st_info, char *line)
{
	if (ft_strncmp(line, "rra", 3) == 0)
	{
		reverse_rotate(st_info->st_a, ' ');
		return (1);
	}
	else if (ft_strncmp(line, "rrb", 3) == 0)
	{
		reverse_rotate(st_info->st_b, ' ');
		return (1);
	}
	else if (ft_strncmp(line, "rrr", 3) == 0)
	{
		reverse_rotate(st_info->st_a, ' ');
		reverse_rotate(st_info->st_b, ' ');
		return (1);
	}
	return (0);
}

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
		/*printf("\n");
		t_node *temp;
		temp = st_info->st_a->tail->next;
		do
		{
			printf("%d\n", temp->content);
			temp = temp->next;
		}
		while (temp != st_info->st_a->tail->next);*/
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

int main(int argc, char *argv[])
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
}