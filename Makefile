# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 15:09:39 by yakary            #+#    #+#              #
#    Updated: 2023/06/12 19:21:54 by ycyr-roy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
#===================================SOURCES====================================#
SRC = get_next_line.c	main.c
#==============================================================================#

HEADERS = libft.h	get_next_line.h
INCLUDES = -I $(MLX_DIR)/include -I $(LIBFT_DIR) -I ./include
OBJS = $(addprefix $(BIN_DIR)/, $(SRC:.c=.o))
NAME = so_long
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -Ofast
LFLAGS = -L$(GLFW_DIR) -lglfw lib/MLX42/build/libmlx42.a -framework Cocoa -framework OpenGL -framework IOKit
RM = rm -f
RM_DIR = rm -rf
#=====================================PATHS=====================================#
GLFW_DIR = /Users/ycyr-roy/.brew/lib
MLX_DIR = lib/MLX42
LIBFT_DIR = lib/libft
GNL_DIR = /include #Might be useless
BIN_DIR = bin
SRC_DIR = src
#==============================================================================#

all: mlx42 libft $(NAME)
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(BLUE)$(BOLD)✅Compiling $(YELLOW)SO_LONG $(BLUE)→ $(RESET)$(CYAN)$(notdir $<)$(RESET)            "
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	@printf $(UP)$(CUT)
	@sleep 1
$(NAME): $(BIN_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ $(OBJS) $(INCLUDES)
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

libft:
	@$(MAKE) -C $(LIBFT_DIR)
mlx42:
	@echo "$(BLUE)$(BOLD)Compiling $(PURPLE)MLX42 $(RESET)$(CYAN)$(notdir $<)$(RESET)"
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4
	@printf $(UP)$(CUT)
clean:
	@rm -rf $(BIN_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
re: fclean all

.PHONY: all, clean, fclean, re, mlx42

#=====================================COLORS=====================================#
# Colors
BLACK       =\033[30m
RED         =\033[31m
GREEN       =\033[32m
YELLOW      =\033[33m
BLUE        =\033[34m
PURPLE      =\033[35m
CYAN        =\033[36m
WHITE       =\033[37m
# Text
ERASE       =\033[2K
RESET       =\033[0m
BOLD        =\033[1m
FAINT       =\033[2m
ITALIC      =\033[3m
UNDERLINE   =\033[4m
INVERT      =\033[7m
STRIKE      =\033[9m
# Background
BG_BLACK    =\033[40m
BG_RED      =\033[41m
BG_GREEN    =\033[42m
BG_YELLOW   =\033[43m
BG_BLUE     =\033[44m
BG_PURPLE   =\033[45m
BG_CYAN     =\033[46m
BG_WHITE    =\033[47m
# Others
UP	="\033[A" #cursor up
CUT	="\033[K" #cut line
#==============================================================================#