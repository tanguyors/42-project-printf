# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: torsini <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 12:25:56 by torsini           #+#    #+#              #
#    Updated: 2024/03/09 12:26:00 by torsini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFT		= ./libft/libft.a
LIBFTDIR	= ./libft

SRC			= ./files

PRINTF_SRCS	= ft_printf.c ft_printf_hex.c ft_printf_p.c \
				ft_printf_un.c ft_printf_funcs.c

OBJS		= $(PRINTF_SRCS:.c=.o)

CC			= cc 
AR			= ar rcs
RM			= rm -rf 
CFLAGS		= -Wall -Wextra -Werror
CP			= cp

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
				$(CP) $(LIBFT) $(NAME)
				@$(AR) $(NAME) $(OBJS)

$(LIBFT):	$(LIBFTDIR)
				@$(MAKE) -C $(LIBFTDIR)

%.o: 		$(SRC)/%.c
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(MAKE) clean -C $(LIBFTDIR)
			@$(RM) $(OBJS)

fclean:		clean
				@$(MAKE) fclean -C $(LIBFTDIR)
				@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
