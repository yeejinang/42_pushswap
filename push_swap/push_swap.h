/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 22:10:23 by yang              #+#    #+#             */
/*   Updated: 2021/11/17 14:06:47 by yang             ###   ########.fr       */
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
	bool	sorted_b;
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
int     getMedian(t_stack *stack, int size);
int		partition(t_stack *head_Ref, int size, t_info *st_info);
void	quickSort(t_stack *head_Ref, int size, t_info *st_info, int sort_num);
void	sort_stack(t_stack *head_Ref, t_info *st_info, int a, int b);
//void	divide_half(t_list *headRef, t_list **tail_a, t_list **tail_b);
void	sort_a(t_info *st_info);
void	sort_b(t_info *st_info);
void	sort_rotate_a(t_info *st_info);
void	sort_rotate_b(t_info *st_info);
void	sort_a3_b0(t_info *st_info);
void	sort_a0_b3(t_info *st_info);
void	sort_a2_b2(t_info *st_info);
void	sort_a3_b2(t_info *st_info);
void	sort_a2_b3(t_info *st_info);
void    sort_ab3(t_info *st_info);
void	sort_rotate(t_info *st_info);


#endif