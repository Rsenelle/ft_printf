# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 22:09:57 by rsenelle          #+#    #+#              #
#    Updated: 2023/10/23 11:49:00 by rsenelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	ft_printf.c\
		ft_match.c\
		lib1.c\
		lib2.c
		
OBJ	= ${SRC:.c=.o}
NAME	= libftprintf.a
CC	= gcc
FLAGS	= -Wall -Werror -Wextra
HEADER	= ft_printf.h
LIBC = ar rc
LIBR = ranlib
RM	= rm -f

${NAME}: ${OBJ} ${HEADER}
	${LIBC} ${NAME} ${OBJ}
	${LIBR} ${NAME}


all: ${NAME}
	
.c.o:	${HEADER}
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}

clean:
	${RM} ${OBJ}
	
fclean: clean
	${RM} ${NAME}
	
re: fclean all

.PHONY: .c.o all clean fclean re 
