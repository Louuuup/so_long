# **************************************************************************** #
#			                                                                     #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 15:09:39 by yakary            #+#    #+#              #
#    Updated: 2023/07/13 22:16:59 by ycyr-roy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
#==============================================================================#
CC = gcc
# CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -Ofast
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -Ofast -g
SRC = \
    main.c         texture_handler.c   initialiser.c    put_tile.c    \
    parse.c        put_tile_utils.c    movements.c      collisions.c \
    layers.c       map_verifs.c        render.c         map_handler.c \
    utils.c		   world_events.c      flood_fill.c		player_death.c \
	on_screen.c
#==============================================================================#
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(BIN_DIR)/, $(SRC:.c=.o))
#==============================================================================#
# the following 'SRCS' and 'OBJS' can be used while working on the project...
# (instead of the previous 'SRC' 'SRCS' 'OBJS' targets and *.c files)
#==============================================================================#
# SRCS = $(wildcard $(SRC_DIR)/*.c)
# OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
#==============================================================================#
SRC_DIR     = src
BIN_DIR     = bin
INC_DIR     = include
MLX_DIR     = lib/MLX42
MLX42       = $(MLX_DIR)/build/libmlx42.a
LIBFT_DIR   = lib/libft
LIBFT       = $(LIBFT_DIR)/libft.a
# commandes shell
MKDIRP = mkdir -p
RM = rm -f
RM_DIR = rm -rf
#==============================================================================#
# headers you want to include
INCLUDES = -I$(LIBFT_DIR) -I$(INC_DIR) -I$(MLX_DIR)/$(INC_DIR)
# things to link
LFLAGS = -L$(GLFW_DIR) $(MLX42) $(LIBFT)
# more things to link (OS check)
ifeq ($(shell uname),Linux)
    LFLAGS += -lglfw -ldl -pthread -lm
else
    LFLAGS += -framework Cocoa -framework OpenGL -framework IOKit -lglfw
endif
# finding glfw (test commented shell command under this)
ifeq ($(shell uname),Linux)
    GLFW_DIR = /usr/lib
else ifeq ($(shell uname),Darwin)
    GLFW_DIR = /Users/$(USER)/.brew/lib
else
    $(error Unsupported operating system: $(shell uname))
endif
#   GLFW_DIR = $(shell brew --prefix glfw)/lib
# (to try instead of GLFW_DIR = /Users/$(USER)/.brew/lib)
#==============================================================================#
all: mlx42 libft $(NAME)
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(BLUE)$(BOLD)✅Compiling $(YELLOW)SO_LONG $(BLUE)→ $(RESET)$(CYAN)$(notdir $<)$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	@printf	$(UP)$(CUT)
$(NAME): $(BIN_DIR) $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS)
	@echo "$(GREEN)$(BOLD)✅ Successfully compiled $(YELLOW)SO_LONG$(RESET)"
$(BIN_DIR):
	@$(MKDIRP) $(BIN_DIR)
libft:
	@$(MAKE) -C $(LIBFT_DIR)
mlx42:
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4
	@echo "$(GREEN)$(BOLD)✅ Successfully compiled $(PURPLE)MLX42$(RESET)"
	@printf $(UP)$(CUT)
clean:
	@$(RM) $(OBJS)
	@$(RM_DIR) $(BIN_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)$(BOLD)✅ Cleaned $(YELLOW)SO_LONG$(RESET)"
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)$(BOLD)✅ Fully cleaned $(YELLOW)SO_LONG$(RESET)"
re: fclean all
.PHONY: all clean fclean re libft mlx42
#=====================================COLORS=====================================#
# Colors
BLACK		=\033[30m
RED			=\033[31m
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
UP    ="\033[A" # cursor up
CUT   ="\033[K" # cut line
#==============================================================================#