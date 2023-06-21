NAME = cub3D
CFLAGS = -I $(INC_DIR) -Wall -Wextra -Werror -MMD -MP

INC_DIR = inc
SRC_DIR = src
SRCS = main.c utils.c cub_validation.c utils_validation.c

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.d))

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	make -s -C libft
	make -s -C minilibx_opengl_20191021
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a ./minilibx_opengl_20191021/libmlx.a -o $@

$(OBJ_DIR) :
	mkdir $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -s -C libft
	make clean -s -C minilibx_opengl_20191021
	rm -rf $(OBJ_DIR)

fclean : clean
	make fclean -s -C libft
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re

-include $(DEPS)