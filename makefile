NAME := fdf
CC := cc
CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR := src/libft/
LIBFT := $(LIBFT_DIR)libft.a

MINILIBX_DIR := src/minilibx-linux/
MINILIBX := $(MINILIBX_DIR)libmlx_Linux.a $(MINILIBX_DIR)libmlx.a

INCLUDES := -I $(LIBFT_DIR)includes/ -I includes/ -I $(MINILIBX_DIR)
LIBRARIES := -L $(MINILIBX_DIR) -lmlx -lX11 -lXext -lm

GRAPHIC_DIR := src/graphic/
GRAPHIC_FILES := graphic.c \
				 init_mlx_data.c \
				 draw_line.c \

C_FILES := fdf.c \
		   $(addprefix $(GRAPHIC_DIR), $(GRAPHIC_FILES)) \

OBJ_DIR := .obj/
OBJ_FILES := $(addprefix $(OBJ_DIR),$(C_FILES:.c=.o))

.PHONY: all makelibft makeminilibx clean fclean re

all: makelibft makeminilibx $(NAME)

makelibft:
	$(MAKE) -C $(LIBFT_DIR)

makeminilibx:
	$(MAKE) -C $(MINILIBX_DIR)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBRARIES) $^ -o $@

$(OBJ_DIR)%.o:%.c | $(OBJ_DIR)$(GRAPHIC_DIR)
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@
	
$(OBJ_DIR)$(GRAPHIC_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
