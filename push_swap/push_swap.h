/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 22:10:23 by yang              #+#    #+#             */
/*   Updated: 2021/11/30 14:15:59 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_node
{
	struct s_node	*prev;
	int				content;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
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
	int		a;
	int		b;
	int		total;
	char	*last;
	char	*instru;
}	t_info;

/* add numbers into stack */
t_stack	*initialize_stack(t_stack *stack);
t_info	*initialize_info(t_info *st_info);
t_node	*lstnew(int content);
void	check_args(t_stack *st_a, char *argv);
int		check_sorted(t_stack *st_a);
int		check_reverse(t_stack *st_a);
void	addfront(t_stack *stack, t_node *new);
t_stack	*add_list(int argc, char *argv[], t_stack *stack_a);
void	free_elem(t_info *st_info);
/* operations */
void	pop(t_stack *stack);
void	swap(t_stack *stack, char print, t_info *st_info);
void	push(t_stack *st_push, t_stack *st_pop, char print, t_info *st_info);
void	rotate(t_stack *stack, char print, t_info *st_info);
void	reverse_rotate(t_stack *stack, char print, t_info *st_info);
/* quicksort */
int		get_median(t_stack *stack, int size);
int		partition(t_stack *head_ref, int size, t_info *st_info);
void	quicksort(t_stack *head_ref, t_info *st_info, int size, int sort_num);
/* sorting function when numbers <= 3 */
void	init_sort(t_stack *head_ref, t_info *st_info, int size, int sort_num);
void	sort_stack(t_stack *head_ref, t_info *st_info, int a, int b);
void	sort_a(t_info *st_info);
void	sort_b(t_info *st_info);
void	sort_rotate_a(t_info *st_info);
void	sort_rotate_b(t_info *st_info);
void	sort_b2(t_info *st_info);
void	sort_a2_b2(t_info *st_info);
void	sort_a3_b0(t_info *st_info);
void	sort_a0_b3(t_info *st_info);
void	sort_a3_b2(t_info *st_info);
void	sort_a3_b3(t_info *st_info);
/* compare with the last operation and print */
void	print_operation(t_info *st_info);
/* checker */
int		process_swap(t_info *st_info, char *line);
int		process_rotate(t_info *st_info, char *line);
int		process_push(t_info *st_info, char *line);
int		process_reverse(t_info *st_info, char *line);

#endif