NAME = cub3D

CFLAGS = -I $(INC_DIR) -Wall -Wextra -Werror -MMD -MP -g -fsanitize=address
CLIB = -lmlx -Lmlx -framework OpenGL -framework Appkit

INC_DIR = ./inc/

SRCS_PARSE = $(addprefix parse/, utils.c file_validation.c identifier_part.c map_part.c middle_part.c set_value_utils.c)
SRCS_RENDER = $(addprefix render/, calculate_wall.c load_texture.c main_loop.c raycasting.c select_texture.c set_info.c draw.c)

SRC_DIR = ./src/
SRCS = main.c $(SRCS_PARSE) $(SRCS_RENDER)
SRCS_NAME = $(addprefix $(SRC_DIR), $(SRCS))

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS_NAME:.c=.o)))
DEPS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS_NAME:.c=.d)))

vpath %.c $(SRC_DIR) $(SRC_DIR)parse/ $(SRC_DIR)render/

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	make bonus -s -C libft
	make all -s -C mlx
	$(CC) $(CFLAGS) $(CLIB) $(OBJS) ./libft/libft.a -o $@

$(OBJ_DIR) :
	mkdir $@

$(OBJ_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -s -C libft
	make clean -s -C mlx
	rm -rf $(OBJ_DIR)

fclean : clean
	make fclean -s -C libft
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re

-include $(DEPS)