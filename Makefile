# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nromptea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 16:09:25 by nromptea          #+#    #+#              #
#    Updated: 2015/12/21 20:18:24 by rporcon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/

SRC_NAME = ft_read.c \
		   ft_error.c \
		   ft_resolv.c \
		   ft_resolv_bis.c \
		   get_next_line.c \
		   ft_norme.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_PATH = ./obj/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INC_PATH = ./include/

INC = $(addprefix -I, $(INC_PATH))

LIB_PATH = ./lib/

LIB_NAME = -lft

LIB = $(addprefix -L,$(LIB_PATH))

NAME = alum1 

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : lib $(NAME)

lib :
	make -C lib

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ) $(LIB) $(LIB_NAME) 

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY: clean fclean re clear lib

clean :
	rm -fv $(OBJ)
	rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean : clean
	make -C lib fclean
	rm -fv $(NAME)
	rm -fv libft.a

re : fclean all
