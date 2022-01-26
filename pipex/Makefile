# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumfred <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 12:30:59 by lumfred           #+#    #+#              #
#    Updated: 2022/01/18 12:30:59 by lumfred          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FLAG = -Wall -Wextra -Werror

HEADER = ./mandatory/pipex.h

BONUS_HEADER = ./bonus/pipex_bonus.h

SRC = ./mandatory/pipex.c \
		./mandatory/functions.c \
		./mandatory/utils/ft_putstr_fd.c \
		./mandatory/utils/ft_split.c \
		./mandatory/utils/ft_strdup.c \
		./mandatory/utils/ft_strjoin.c \
		./mandatory/utils/ft_strlen.c \
		./mandatory/utils/ft_strncmp.c \
		./mandatory/utils/ft_substr.c

BONUS_SRC = ./bonus/pipex_bonus.c \
		./bonus/getters_bonus.c \
		./bonus/free_bonus.c \
		./bonus/errors_bonus.c \
		./bonus/utils_bonus/ft_putstr_fd.c \
		./bonus/utils_bonus/ft_split.c \
		./bonus/utils_bonus/ft_strchr.c \
		./bonus/utils_bonus/ft_strdup_gnl.c \
		./bonus/utils_bonus/ft_strdup.c \
		./bonus/utils_bonus/ft_strjoin_gnl.c \
		./bonus/utils_bonus/ft_strjoin.c \
		./bonus/utils_bonus/ft_strlen.c \
		./bonus/utils_bonus/ft_strncmp.c \
		./bonus/utils_bonus/ft_substr_gnl.c \
		./bonus/utils_bonus/ft_substr.c \
		./bonus/utils_bonus/get_next_line.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC := gcc

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) -o $(NAME)
	@echo $(NAME) compiled

bonus: $(BONUS_OBJ) $(BONUS_HEADER)
	@$(CC) $(BONUS_OBJ) -o $(NAME)
	@echo $(NAME) bonus compiled

clean:
	@rm -f $(OBJ)
	@rm -f $(BONUS_OBJ)
	@echo $(NAME) object files cleaned

fclean: clean
	@rm -f $(NAME)
	@echo $(NAME) cleaned

re: fclean all

.PHONY: re, clean, fclean, all, bonus
