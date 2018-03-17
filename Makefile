#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 09:37:14 by rhallste          #+#    #+#              #
#    Updated: 2018/03/16 19:20:12 by rhallste         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= 	fdf
CC			=	gcc
EXTRA_FLAGS =	-Weverything -Wno-cast-qual
CFLAGS		=	-Wall -Werror -Wextra -g

LIBFT		=	libft/libftprintf.a

MLX			=	minilibx/libmlx.a

FILES		=	main		\
				parsing 	\
				error		\
				transform	

SRCS		=	$(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS		=	$(addprefix src/, $(addsuffix .o, $(FILES)))

all: $(NAME)

$(OBJS): $(SRCS)

$(LIBFT):
	@make -C libft/

$(MLX):
	@make -C minilibx/

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME) -framework OpenGL -framework AppKit

clean:
	@rm -rf $(OBJS)
	@make -C libft/ clean
	@make -C minilibx/ clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean all

.SILENT: $(OBJS)
