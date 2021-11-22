/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 22:10:23 by yang              #+#    #+#             */
/*   Updated: 2021/11/22 15:51:40 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TWO 2
# define THREE 3
# define MORE_THAN_THREE 4

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_node
{
	struct s_node	*prev;
	int				content;
	struct s_node	*next;
}	t_node;

typedef	struct s_stack
{
	t_node	*tail;
	int		count;
	int		rotate_count;
	int		sort_num;
}	t_stack;

typedef struct s_info
{
	t_stack	*st_a;
	t_stack	*st_b;
	int		half_len;
	bool	first_round;
	int		a;
	int		b;
}	t_info;

/*typedef struct s_info
{
	int		rotate_count;
	int		numbers_a;
	int		numbers_b;
	bool	first_round;
	bool	rotate_a;
	bool	rotate_b;
	bool	sorted_b;
	t_list	**stack_a;
	t_list	**stack_b;
}	t_info; */

t_node	*lstnew(int content);
void	addfront(t_stack *stack, t_node *new);
void	pop(t_stack *stack);
void	swap(t_stack *stack, char print);
void	push(t_stack *st_push, t_stack *st_pop, char print);
void	rotate(t_stack *stack, char print);
void	reverse_rotate(t_stack *stack, char print);
int     get_median(t_stack *stack, int size);
int		partition(t_stack *head_ref, int size, t_info *st_info);
void	quicksort(t_stack *head_ref, t_info *st_info, int size, int sort_num);
void	init_sort(t_stack *head_ref, t_info *st_info, int size, int sort_num);
void	sort_stack(t_stack *head_ref, t_info *st_info, int a, int b);
void	sort_a(t_info *st_info);
void	sort_b(t_info *st_info);
void	sort_rotate_a(t_info *st_info);
void	sort_rotate_b(t_info *st_info);
void	sort_a3_b0(t_info *st_info);
void	sort_a0_b3(t_info *st_info);
void	sort_a2_b2(t_info *st_info);
void	sort_a3_b2(t_info *st_info);
void	sort_a2_b3(t_info *st_info);
void    sort_a3_b3(t_info *st_info);
void	sort_ab3(t_info *st_info);
void	sort_rotate(t_info *st_info);

/*
100 numbers:
100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 
50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

72 38 8 22 52 88 50 96 1 62 61 91 27 32 23 30 3 43 75 69 34 18 68 77 9 20 76 17 84 78 64 36 100 80 40 79 39 42 26 37 98 13 65 5 15 99 83 16 54 82 92 97 60 57 95 87 21 45 89 10 58 73 14 55 67 11 66 90 86 33 53 29 51 46 2 6 41 47 49 71 63 25 59 31 19 70 7 44 74 35 81 28 85 93 12 56 4 48 24 94


check this: -> infinity loop
./test 2 4 3 16 19 5 17 1 18 20 9 11 13 21 25 15 12 14 22 23 10 24 7 8 6
*/
#endif