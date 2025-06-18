# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 19:26:12 by tkitago           #+#    #+#              #
#    Updated: 2024/12/11 20:10:03 by tkitago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = cc
CFLAGS = -Wall -Werror -Wextra -g -O2
DEBUG_FLAGS = -g

LIBFT_PATH = savelibft
MLX_PATH = minilibx-linux

SRC_FILES = init.c julia.c main.c mandelbrot.c\
			mouse_key.c utils.c\
			
OBJ_FILES = $(SRC_FILES:.c=.o)

LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.a

NAME = fractol 

all: $(NAME)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -lX11 -lXext -lm
	
%.o: %.c 
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -I$(MLX_PATH) -c -o $@ $<	

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)
	

$(MLX):
	$(MAKE) -C $(MLX_PATH)
	

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean
	rm -r $(OBJ_FILES)


fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(MLX_PATH) fclean
	rm -f $(LIBFT_PATH)/libft.a
	rm -f $(MLX_PATH)/libmlx.a
	rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re
