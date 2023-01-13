NAME 		:= fdf
CFLAGS 		:= -fsanitize=address -g3 -Wextra -Wall -Werror -Wunreachable-code -Ofast
FRAMEWORKS 	:= -framework Cocoa -framework OpenGL -framework IOKit
LIBMLX 		:= lib/MLX42
LIBGLFW 	:= lib/glfw-3.3.8
SRC_DIR 	:= src

MLX42 		:= $(LIBMLX)/libmlx42.a
GLFW3 		:= $(LIBGLFW)/lib-x86_64/libglfw3.a
SRCS 		:= $(addprefix $(SRC_DIR)/, \
				window_test.c)
OBJS 		:= $(SRCS:.c=.o)

all: libmlx $(NAME)

libmlx:
	@$(MAKE) HEADERS='-I ../glfw-3.3.8/include' -C $(LIBMLX)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX42) $(GLFW3) $(FRAMEWORKS) -o $(NAME) && \
		echo "Compilation successful"

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