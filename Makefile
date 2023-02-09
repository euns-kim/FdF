# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 19:05:03 by eunskim           #+#    #+#              #
#    Updated: 2023/02/09 17:49:29 by eunskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= fdf
CC			:= cc
CFLAGS 		:= -fsanitize=address -g3 -Wextra -Wall -Werror -Wunreachable-code -Ofast
FRAMEWORKS 	:= -framework Cocoa -framework OpenGL -framework IOKit
LIBMLX 		:= lib/MLX42
LIBGLFW 	:= lib/glfw-3.3.8
LIBFT		:= lib/libft
LIBGNL		:= lib/get_next_line
SRC_DIR 	:= src
HEADERS		:= -I $(LIBMLX)/include/MLX42/ -I $(LIBFT) -I $(LIBGNL)
MLX42 		:= $(LIBMLX)/libmlx42.a
GLFW3 		:= $(LIBGLFW)/lib-x86_64/libglfw3.a
LIBC		:= $(LIBFT)/libft.a
GNL			:= $(LIBGNL)/get_next_line.a
SRCS 		:= $(addprefix $(SRC_DIR)/, \
				fdf.c \
				get_map.c \
				get_map_utils.c \
				draw_map.c \
				update_pixel.c \
				rotate.c \
				keyhooks.c \
				gradient.c \
				scale.c)
OBJS 		:= $(SRCS:.c=.o)

#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

#//= Make Rules =//#
all: libmlx libft libgnl $(NAME)

libmlx:
	@$(MAKE) HEADERS='-I ../glfw-3.3.8/include' -C $(LIBMLX)

libft:
	@$(MAKE) -C $(LIBFT)

libgnl:
	@$(MAKE) -C $(LIBGNL)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(MLX42) $(GLFW3) $(LIBC) $(GNL) $(FRAMEWORKS) -o $(NAME) && \
	echo "$(BLUE)$(BOLD)Compilation successful!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ 

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBGNL) fclean

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all. clean, fclean, re, libmlx, libft, libgnl
