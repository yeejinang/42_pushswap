# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yang <yang@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/16 10:41:40 by yang              #+#    #+#              #
#    Updated: 2021/11/24 19:17:48 by yang             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3 -I.

LIBFTDIC	= ../libft

LIBFT		= libft.a

PUSH_SWAP	= push_swap

CHECKER		= checker

SRCS_BOTH	= check_args.c operations.c parse_arg.c utils.c

SRCS		= median.c partition.c quicksort.c sort_stack.c sort_1.c sort_2.c sort_3.c \
				sort_4.c sort_5.c sort_6.c quicksort_main.c

SRCS_CHECKER	= checker.c

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
			rm -rf $(LIBFT)

fclean:		clean
			rm -f $(PUSH_SWAP)
			rm -f $(CHECKER)

re:			fclean all

.PHONY:		all clean fclean re bonus norm