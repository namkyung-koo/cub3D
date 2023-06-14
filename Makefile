NAME = cub3D
CFLAGS = -I $(INC_DIR) -Wall -Wextra -Werror -MMD -MP

INC_DIR = inc
SRC_DIR = src
SRCS = main.c

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.d))

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	make bonus -s -C libft
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $@

$(OBJ_DIR) :
	mkdir $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -s -C libft
	rm -rf $(OBJ_DIR)

fclean : clean
	make fclean -s -C libft
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re

-include $(DEPS)