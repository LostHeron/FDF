NAME := fdf
CC := cc
CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR := src/libft/
LIBFT := $(LIBFT_DIR)libft.a

MINILIBX_DIR := src/minilibx-linux/
MINILIBX := $(MINILIBX_DIR)libmlx_Linux.a $(MINILIBX_DIR)libmlx.a

INCLUDES := -I $(LIBFT_DIR)includes/


C_FILES := fdf.c \

OBJ_DIR := .obj/
OBJ_FILES := $(addprefix $(OBJ_DIR),$(C_FILES:.c=.o))

all: makelibft makeminilibx $(NAME)

makelibft:
	$(MAKE) -C $(LIBFT_DIR)

makeminilibx:
	$(MAKE) -C $(MINILIBX_DIR)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

$(OBJ_DIR)%.o:%.c | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@
	
$(OBJ_DIR):
	mkdir -p $@
