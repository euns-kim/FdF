# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 19:05:03 by eunskim           #+#    #+#              #
#    Updated: 2023/01/29 20:28:41 by eunskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= fdf
CFLAGS 		:= -fsanitize=address -g3 -Wextra -Wall -Werror -Wunreachable-code -Ofast
FRAMEWORKS 	:= -framework Cocoa -framework OpenGL -framework IOKit
LIBMLX 		:= lib/MLX42
LIBGLFW 	:= lib/glfw-3.3.8
LIBGNL		:= lib/get_next_line
SRC_DIR 	:= src
HEADERS		:= -I $(LIBMLX)/include/MLX42/
MLX42 		:= $(LIBMLX)/libmlx42.a
GLFW3 		:= $(LIBGLFW)/lib-x86_64/libglfw3.a
GNL			:= $(LIBGNL)/get_next_line.a
SRCS 		:= $(addprefix $(SRC_DIR)/, \
				main.c \
				get_map.c \
				get_map_utils.c \
				draw_map.c \
				update_point.c \
				keyhooks.c)
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
all: libmlx libgnl $(NAME)

libmlx:
	@$(MAKE) HEADERS='-I ../glfw-3.3.8/include' -C $(LIBMLX)

libgnl:
	@$(MAKE) -C $(LIBGNL)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(MLX42) $(GLFW3) $(GNL) $(FRAMEWORKS) -o $(NAME) && \
	echo "$(BLUE)$(BOLD)Compilation successful!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBGNL) fclean

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all. clean, fclean, re, libmlx, libgnl
