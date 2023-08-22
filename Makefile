# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 12:02:28 by hgeffroy          #+#    #+#              #
#    Updated: 2023/07/25 10:20:58 by hgeffroy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME = philo
FLAGS = -Wall -Wextra -Werror -Iheader -MMD -MP -fsanitize=address -g3
CC = cc
RM = rm -f
OBJ_DIR = .objs/
SRC_DIR = src/
HEADER = header/philo.h

#Files

SRC_F = ft_atoi.c \
		ft_isstrdigit.c \
		ft_strlen.c \
		ft_isdigit.c \
		ft_strncmp.c \
		parsing.c \
		init.c \
		time.c \
		core.c \
		free.c \
		exec.c \
		main.c
		
OBJ = $(addprefix $(OBJ_DIR), $(SRC_F:.c=.o))

DEPS = $(OBJ:.o=.d)

#Rules

all :
	make $(NAME)

-include $(DEPS)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(LIBFT_DIR)$(LIBFT) $(HEADER) Makefile
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@ -I.

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT_DIR)$(LIBFT) -o $@ -I.

clean :
	$(RM) -r $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean 
	make all

.PHONY : re fclean clean all