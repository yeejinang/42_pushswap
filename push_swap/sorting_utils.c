/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:11:08 by yang              #+#    #+#             */
/*   Updated: 2021/11/25 16:18:10 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operation(t_info *st_info)
{
	printf("last: %s\t current: %s", st_info->last, st_info->instru);
	//if (st_info->last[0] == '\0')
		//return ;
	if (!(ft_strncmp(st_info->last, "sa\n", 3))
			&& !(ft_strncmp(st_info->instru, "sb\n", 3)))
		ft_strlcpy(st_info->instru, "ss\n", 4);
	else if (!(ft_strncmp(st_info->last, "sb\n", 3))
				&& !(ft_strncmp(st_info->instru, "sa\n", 3)))
		ft_strlcpy(st_info->instru, "ss\n", 4);
	else if (!(ft_strncmp(st_info->last, "ra\n", 3))
			&& !(ft_strncmp(st_info->instru, "rb\n", 3)))
		ft_strlcpy(st_info->instru, "rr\n", 4);
	else if (!(ft_strncmp(st_info->last, "rb\n", 3))
				&& !(ft_strncmp(st_info->instru, "ra\n", 3)))
		ft_strlcpy(st_info->instru, "rr\n", 4);
	else if (!(ft_strncmp(st_info->last, "rra\n", 4))
			&& !(ft_strncmp(st_info->instru, "rrb\n", 4)))
		ft_strlcpy(st_info->instru, "rrr\n", 5);
	else if (!(ft_strncmp(st_info->last, "rrb\n", 4))
				&& !(ft_strncmp(st_info->instru, "rra\n", 4)))
		ft_strlcpy(st_info->instru, "rrr\n", 5);
	else if (!(ft_strncmp(st_info->last, "pa\n", 3))
			&& !(ft_strncmp(st_info->instru, "pb\n", 3)))
		ft_bzero(st_info->instru, 5);
	else if (!(ft_strncmp(st_info->last, "pb\n", 3)
				&& !(ft_strncmp(st_info->instru, "pa\n", 3))))
		ft_bzero(st_info->instru, 5);
	printf("print current: %s\n", st_info->instru);
	ft_putstr_fd(st_info->instru, 1);
	ft_strlcpy(st_info->last, st_info->instru, ft_strlen(st_info->instru) + 1);
	//printf("print last: %s", st_info->last);
	ft_bzero(st_info->instru, 5);
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