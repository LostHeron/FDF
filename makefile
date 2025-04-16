NAME := fdf
NAME_BONUS := fdf_bonus
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
				 convert_map.c \
				 fill_new_vec.c \
				 fill_vec_tmp.c \
				 convert_points_coo.c \
				 copy_map_vec.c \

PRINTING_DIR := src/printing/
PRINTING_FILES := print_error.c \
				  print_error_utils.c \

GRAPHIC_DIR := src/graphic/
GRAPHIC_FILES := graphic.c \
				 init_mlx_data.c \
				 set_rotations.c \
				 get_scale_factor.c \
				 calc_points.c \
				 draw_line.c \
				 draw_points.c \
				 clear_image.c \
				 clear_and_print.c \

KEY_HOOKS_DIR := src/key_hooks/
KEY_HOOKS_FILES := key_press.c \

GRAPHIC_DIR_BONUS := src/graphic/
GRAPHIC_FILES_BONUS := graphic_bonus.c \
					   init_mlx_data.c \
				 	   set_rotations.c \
				 	   get_scale_factor.c \
				 	   calc_points.c \
				 	   draw_line.c \
				 	   draw_points.c \
				 	   clear_image.c \
				 	   clear_and_print.c \

KEY_HOOKS_DIR_BONUS := src/key_hooks/
KEY_HOOKS_FILES_BONUS := key_press_bonus.c \
						 key_release_bonus.c \
						 key_hook_shift_bonus.c \
						 key_hook_no_shift_bonus.c \
						 modify_rot_bonus.c \
						 modify_rot_neg_bonus.c \
						 modify_height_factor_bonus.c \
						 modify_zoom_factor_bonus.c \
						 hooks_utils_bonus.c \

C_FILES := fdf.c \
		   $(addprefix $(PRINTING_DIR), $(PRINTING_FILES)) \
		   $(addprefix $(PARSING_DIR), $(PARSING_FILES)) \
		   $(addprefix $(GRAPHIC_DIR), $(GRAPHIC_FILES)) \
		   $(addprefix $(KEY_HOOKS_DIR), $(KEY_HOOKS_FILES)) \

C_FILES_BONUS := fdf_bonus.c \
		   		 $(addprefix $(PRINTING_DIR), $(PRINTING_FILES)) \
		   		 $(addprefix $(PARSING_DIR), $(PARSING_FILES)) \
				 $(addprefix $(GRAPHIC_DIR_BONUS), $(GRAPHIC_FILES_BONUS)) \
		   		 $(addprefix $(KEY_HOOKS_DIR_BONUS), $(KEY_HOOKS_FILES_BONUS)) \

OBJ_DIR_DEBUG := .obj_debug/
OBJ_DIR := .obj/
OBJ_FILES := $(addprefix $(OBJ_DIR),$(C_FILES:.c=.o))
OBJ_FILES_BONUS := $(addprefix $(OBJ_DIR),$(C_FILES_BONUS:.c=.o))
D_FILES := $(OBJ_FILES:.o=.d)
D_FILES_BONUS := $(OBJ_FILES_BONUS:.o=.d)

.PHONY: all git makelibft makeminilibx clean fclean re bonus clean_bonus fclean_bonus re_bonus debug debug_clean debug_fclean debug_re

all: makelibft makeminilibx $(NAME)

bonus: makelibft makeminilibx $(NAME_BONUS)

git_init:
	git submodule update --init

git_update:
	git submodule update --init --remote --recursive

makelibft:
	$(MAKE) -C $(LIBFT_DIR)

makeminilibx:
	$(MAKE) CFLAGS="-O3 -I . -I ../" -C $(MINILIBX_DIR)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBRARIES) $^ -o $@


$(NAME_BONUS): $(OBJ_FILES_BONUS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBRARIES) $^ -o $@

-include $(D_FILES)
-include $(D_FILES_BONUS)

$(OBJ_DIR)%.o:%.c | $(OBJ_DIR)$(GRAPHIC_DIR) $(OBJ_DIR)$(PARSING_DIR) $(OBJ_DIR)$(PRINTING_DIR) $(OBJ_DIR)$(KEY_HOOKS_DIR)
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@
	
$(OBJ_DIR)$(GRAPHIC_DIR):
	mkdir -p $@

$(OBJ_DIR)$(PARSING_DIR):
	mkdir -p $@

$(OBJ_DIR)$(PRINTING_DIR):
	mkdir -p $@

$(OBJ_DIR)$(KEY_HOOKS_DIR):
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

clean_bonus:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean_bonus:
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) clean
	rm -rf $(NAME_BONUS)

re_bonus:
	$(MAKE) fclean_bonus
	$(MAKE)	bonus 

debug:
	$(MAKE) CFLAGS="$(CFLAGS) -g3" OBJ_DIR="$(OBJ_DIR_DEBUG)" all

debug_clean:
	$(MAKE) CFLAGS="$(CFLAGS) -g3" OBJ_DIR="$(OBJ_DIR_DEBUG)" clean

debug_fclean:
	$(MAKE) CFLAGS="$(CFLAGS) -g3" OBJ_DIR="$(OBJ_DIR_DEBUG)" fclean

debug_re:
	$(MAKE) CFLAGS="$(CFLAGS) -g3" OBJ_DIR="$(OBJ_DIR_DEBUG)" re

debugrun:
	$(MAKE) debug
	valgrind --track-fds=yes -s --leak-check=full ./$(NAME) map/1.fdf


debug_bonus:
	$(MAKE) CFLAGS="$(CFLAGS) -g3" OBJ_DIR="$(OBJ_DIR_DEBUG)" bonus

debug_clean_bonus:
	$(MAKE) CFLAGS="$(CFLAGS) -g3" OBJ_DIR="$(OBJ_DIR_DEBUG)" clean_bonus

debug_fclean_bonus:
	$(MAKE) CFLAGS="$(CFLAGS) -g3" OBJ_DIR="$(OBJ_DIR_DEBUG)" fclean_bonus

debug_re_bonus:
	$(MAKE) CFLAGS="$(CFLAGS) -g3" OBJ_DIR="$(OBJ_DIR_DEBUG)" re_bonus

debugrun_bonus:
	$(MAKE) debug_bonus
	valgrind --track-fds=yes -s --leak-check=full ./$(NAME_BONUS) map/1.fdf
