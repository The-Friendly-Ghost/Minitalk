# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cpost <cpost@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/07 14:00:19 by cpost         #+#    #+#                  #
#    Updated: 2022/03/31 11:14:08 by cpost         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#=====================================#
#========= General variables =========#
#=====================================#

SERVER := server
CLIENT := client
INCLUDE_DIR := include
SRC_DIR := src
LIBS_DIR := libs
OBJS_DIR := objs

#=====================================#
#============ Input files ============#
#=====================================#

LIBS := $(LIBS_DIR)/libft/libft.a

LIBS_HEADERS := -I $(LIBS_DIR)/libft/include


INC := -I $(INCLUDE_DIR) $(LIBS_HEADERS)

SRCS := client.c \
		server.c \

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

#=====================================#
#========= Command arguments =========#
#=====================================#

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g $(INC)

#=====================================#
#=============== Rules ===============#
#=====================================#

objs/%.o:src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $^
	@echo "🔨 Compiling: $^"
	
all: $(SERVER) $(CLIENT)

$(SERVER): objs/server.o $(LIBS)
	@$(CC) objs/server.o $(CFLAGS) $(LIBS) -o $(SERVER)
	@echo "✅ Built $(NAME)"

$(CLIENT): objs/client.o $(LIBS)
	@$(CC) objs/client.o $(CFLAGS) $(LIBS) -o $(CLIENT)
	@echo "✅ Built $(NAME)"

$(LIBS_DIR)/libft/libft.a:
	@make -C $(LIBS_DIR)/libft

run: $(NAME)
	./$(NAME)

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make fclean -C $(LIBS_DIR)/libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all re run clean fclean