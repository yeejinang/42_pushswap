/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:14:18 by yang              #+#    #+#             */
/*   Updated: 2021/11/23 18:19:46 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_non_numeric(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] == '-' || argv[0] == '+')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	check_duplicate(t_stack *st_a, int next_num)
{
	t_node	*temp_a;

	if (!st_a->tail)
		return (0);
	temp_a = st_a->tail;
	while (temp_a != st_a->tail->next)
	{
		if (temp_a->content == next_num)
			return (1);
		temp_a = temp_a->prev;
	}
	if (temp_a->content == next_num)
		return (1);
	return (0);
}

static int	check_min_max(char *argv)
{
	int		len;
	char	sign;

	len = ft_strlen(argv);
	sign = 'p';
	if (argv[0] == '+' || argv[0] == '-')
		len--;
	if (argv[0] == '-')
		sign = '-';
	if (argv[0] == '+')
		sign = '+';
	if (len > 10)
		return (1);
	else if (len < 10)
		return (0);
	else
	{
		if ((sign == 'p' && ft_strncmp(argv, "2147483647", 10) > 0)
			|| (sign == '+' && ft_strncmp(argv + 1, "2147483647", 10) > 0)
			|| (sign == '-' && ft_strncmp(argv + 1, " 2147483648", 10) > 0))
			return (1);
		else
			return (0);
	}
}

void	check_args(t_stack *st_a, char *argv)
{
	if (check_non_numeric(argv) || check_duplicate(st_a, ft_atoi(argv))
		|| check_min_max(argv))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}
