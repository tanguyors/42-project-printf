# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: torsini <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 11:00:22 by torsini           #+#    #+#              #
#    Updated: 2024/03/04 11:00:28 by torsini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAG = -Wall -Werror -Wextra

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
      ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c\
      ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
      ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c\
      ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
      ft_strmapi.c ft_striteri.c\
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\

HEADER = libft.h

OBJ = $(SRC:.c=.o)

NAME = libft.a

$(NAME): $(OBJ)
	@$(CC) $(FLAG) -c $(SRC)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

