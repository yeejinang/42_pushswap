# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yang <yang@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/16 10:41:40 by yang              #+#    #+#              #
#    Updated: 2021/11/17 15:06:04 by yang             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3 -I.

LIBFTDIC	= ../libft

LIBFT		= libft.a

TEST		= test

$(LIBFT)	:
				make -C $(LIBFTDIC)

$(TEST)		:	parse_arg.c operations.c median.c partition.c quicksort.c \
				sort_stack.c sort_1.c sort_2.c sort_3.c sort_4.c sort_5.c sort_6.c
				$(CC) parse_arg.c operations.c median.c partition.c quicksort.c \
				sort_stack.c sort_1.c sort_2.c sort_3.c sort_4.c sort_5.c sort_6.c -o $(TEST) $(LIBFTDIC)/$(LIBFT)

all			: $(LIBFT)
				make $(TEST)

bonus		: all

clean:
			rm -f *.o
			rm -rf $(LIBFT)

fclean:		clean
			rm -f $(TEST)

re:			fclean all

.PHONY:		all clean fclean re bonus norm