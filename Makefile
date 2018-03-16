#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 09:37:14 by rhallste          #+#    #+#              #
#    Updated: 2018/03/16 00:40:55 by rhallste         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= 	fdf
CC			=	gcc
EXTRA_FLAGS =	-Weverything -Wno-cast-qual
CFLAGS		=	-Wall -Werror -Wextra

LIBFT		=	libft/libftprintf.a

FILES		=	main	\
				parsing \
				error	

SRCS		=	$(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS		=	$(addprefix src/, $(addsuffix .o, $(FILES)))

all: $(NAME)

$(OBJS): $(SRCS)

$(LIBFT):
	@make -C libft/

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@make -C libft/ clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean all

.SILENT: $(OBJS)
