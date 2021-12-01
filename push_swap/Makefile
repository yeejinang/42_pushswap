# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yang <yang@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/16 10:41:40 by yang              #+#    #+#              #
#    Updated: 2021/11/30 14:19:23 by yang             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3 -I.

LIBFTDIC	= ../libft

LIBFT		= libft.a

PUSH_SWAP	= push_swap

CHECKER		= checker

SRCS_BOTH	= check_args.c operations.c utils.c print_operation.c

SRCS		= median.c partition.c quicksort.c sort_stack.c \
				sorting_1.c sorting_2.c sorting_3.c

SRCS_CHECKER	= checker.c checker_process.c

OBJS_BOTH	= $(SRCS_BOTH:.c=.o)

OBJS		= $(SRCS:.c=.o)

OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

$(LIBFT)	:
				make -C $(LIBFTDIC)

$(PUSH_SWAP)	: $(OBJS_BOTH) $(OBJS)
				$(CC) $(CFLAGS) $(OBJS_BOTH) $(OBJS) -o $(PUSH_SWAP) $(LIBFTDIC)/$(LIBFT)

$(CHECKER)	: $(OBJS_BOTH) $(OBJS_CHECKER)
				$(CC) $(CFLAGS) $(OBJS_BOTH) $(OBJS_CHECKER) -o $(CHECKER) $(LIBFTDIC)/$(LIBFT)

all			: $(LIBFT)
				make $(PUSH_SWAP)
				make $(CHECKER)

bonus		: all

clean:
			rm -f *.o
			rm -f ../libft/*.o
			rm -rf $(LIBFT)

fclean:		clean
			rm -f $(PUSH_SWAP)
			rm -f $(CHECKER)

re:			fclean all

.PHONY:		all clean fclean re bonus norm