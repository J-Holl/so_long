NAME = so_long

# Compile
CC = clang
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
MLXFLAG = -lmlx -lXext -lX11 -lm -lbsd
INC = -I$(INC_DIR)
HEADER = $(INC_DIR)/so_long.h

# Location
MLX_DIR = minilibx_linux
SRC_DIR = src
INC_DIR = inc

# Source files
MAIN = so_long.c
PARSING = parsing.c parsing_map.c parsing_is_map_valid.c
MISC = global_utils.c ft_isalpha.c ft_isdigit.c
INIT = init.c init_after_parsing.c
GET_NEXT_LINE = get_next_line.c get_next_line_utils.c gnl_str_free.c
EXIT = exit_error.c free.c exit_no_error.c
MOVE = hooks.c player.c count_print_move.c
RENDER = color.c render.c
SRC = $(addprefix src/, $(MAIN)) \
	  $(addprefix src/parsing/, $(PARSING)) \
	  $(addprefix src/misc/, $(MISC)) \
	  $(addprefix src/init/, $(INIT)) \
	  $(addprefix src/move/, $(MOVE)) \
	  $(addprefix src/render/, $(RENDER)) \
	  $(addprefix src/get_next_line/, $(GET_NEXT_LINE)) \
	  $(addprefix src/exit/, $(EXIT)) 

# Object files
OBJ = $(SRC:.c=.o)

# Patern rule 
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c ${HEADER}
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ) -L $(MLX_DIR) $(MLXFLAG)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
