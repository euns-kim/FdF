NAME 		:= fdf
CFLAGS 		:= -fsanitize=address -g3 -Wextra -Wall -Werror -Wunreachable-code -Ofast
FRAMEWORKS 	:= -framework Cocoa -framework OpenGL -framework IOKit
LIBMLX 		:= lib/MLX42
LIBGLFW 	:= lib/glfw-3.3.8
SRC_DIR 	:= src
HEADERS		:= -I $(LIBMLX)/include/MLX42
MLX42 		:= $(LIBMLX)/libmlx42.a
GLFW3 		:= $(LIBGLFW)/lib-x86_64/libglfw3.a
SRCS 		:= $(addprefix $(SRC_DIR)/, \
				draw_line_test.c \
				isometric_projection.c)
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
all: libmlx $(NAME)

libmlx:
	@$(MAKE) HEADERS='-I ../glfw-3.3.8/include' -C $(LIBMLX)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(MLX42) $(GLFW3) $(FRAMEWORKS) -o $(NAME) && \
	echo "$(BLUE)$(BOLD)Compilation successful!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
		@rm -f $(NAME)
		@$(MAKE) -C $(LIBMLX) fclean

re: clean all

.PHONY: all. clean, fclean, re, libmlx
