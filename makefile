NAME := fdf
CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP

LIBFT_DIR := src/libft/
LIBFT := $(LIBFT_DIR)libft.a

MINILIBX_DIR := src/minilibx-linux/
MINILIBX := $(MINILIBX_DIR)libmlx_Linux.a $(MINILIBX_DIR)libmlx.a

INCLUDES := -I $(LIBFT_DIR)includes/ -I includes/ -I $(MINILIBX_DIR)
LIBRARIES := -L $(MINILIBX_DIR) -lmlx -lX11 -lXext -lm

PARSING_DIR := src/parsing/
PARSING_FILES := parsing.c \
				 read_map.c \

PRINTING_DIR := src/printing/
PRINTING_FILES := print_error.c \

GRAPHIC_DIR := src/graphic/
GRAPHIC_FILES := graphic.c \
				 init_mlx_data.c \
				 draw_line.c \
				 draw_points.c \
				 clear_image.c \
				 key_hooks.c \
				 set_rotations.c \
				 modify_rot.c \
				 calc_points.c \

C_FILES := fdf.c \
		   $(addprefix $(GRAPHIC_DIR), $(GRAPHIC_FILES)) \
		   $(addprefix $(PARSING_DIR), $(PARSING_FILES)) \
		   $(addprefix $(PRINTING_DIR), $(PRINTING_FILES)) \

OBJ_DIR_DEBUG := .obj_debug/
OBJ_DIR := .obj/
OBJ_FILES := $(addprefix $(OBJ_DIR),$(C_FILES:.c=.o))
D_FILES := $(OBJ_FILES:.o=.d)

.PHONY: all makelibft makeminilibx clean fclean re

all: makelibft makeminilibx $(NAME)

makelibft:
	$(MAKE) -C $(LIBFT_DIR)

makeminilibx:
	$(MAKE) CFLAGS="-O3 -I . -I ../" -C $(MINILIBX_DIR)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBRARIES) $^ -o $@

-include $(D_FILES)

$(OBJ_DIR)%.o:%.c | $(OBJ_DIR)$(GRAPHIC_DIR) $(OBJ_DIR)$(PARSING_DIR) $(OBJ_DIR)$(PRINTING_DIR)
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@
	
$(OBJ_DIR)$(GRAPHIC_DIR):
	mkdir -p $@

$(OBJ_DIR)$(PARSING_DIR):
	mkdir -p $@

$(OBJ_DIR)$(PRINTING_DIR):
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

debug:
	$(MAKE) CFLAGS="$(CFLAGS) -g3" OBJ_DIR="$(OBJ_DIR_DEBUG)" all

debug_clean:
	$(MAKE) CFLAGS="$(CFLAGS) -g3" OBJ_DIR="$(OBJ_DIR_DEBUG)" clean

debug_fclean:
	$(MAKE) CFLAGS="$(CFLAGS) -g3" OBJ_DIR="$(OBJ_DIR_DEBUG)" fclean

debug_re:
	$(MAKE) CFLAGS="$(CFLAGS) -g3" OBJ_DIR="$(OBJ_DIR_DEBUG)" re

