# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xeherzi <xeherzi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 11:51:57 by xeniaherzi        #+#    #+#              #
#    Updated: 2023/08/23 12:01:37 by xeherzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME         = pipex
FLAGS        = -Wall -Wextra -Werror
CC           = gcc
LINKFLAGS    = -I include -I../libft

SOURCEFILES  := pipex.c \
                path.c \
				error_handling.c \

OBJ_DIR      := objs/
OFILES       := $(addprefix $(OBJ_DIR), $(SOURCEFILES:.c=.o))
SRC_DIR      := srcs/
SOURCES      := $(addprefix $(SRC_DIR), $(SOURCEFILES))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OFILES) $(SRCS)
	@$(CC) $(OFILES) $(COMPIL_FLAGS) $(LINKFLAGS) libft/libft.a -o $(NAME)
	@printf "\n$(NAME) compiled!\n"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) -c $< $(COMPIL_FLAGS) $(LINKFLAGS) -o $@ && printf "Compiling $(notdir $<) \n"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@$(RM) -rf $(OBJ_DIR)
	@printf "Files cleaned!\n"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
