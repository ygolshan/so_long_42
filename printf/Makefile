# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 09:41:19 by ygolshan          #+#    #+#              #
#    Updated: 2023/05/28 13:13:51 by ygolshan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	libftprintf.a
CC				=	cc
FLAGS			=	-Wall -Wextra -Werror
INCLUDES		=	./include
OBJ				=	$(SRC:.c=.o)
SRC 			=	$(shell find . -name "ft_print_hex.c" -o -name "ft_print_ptr.c"\
					-o -name "ft_print_u.c" -o -name "ft_printf.c" -o -name "ft_uitoa.c" -type f)

all: $(NAME)
%.o: %.c
	$(CC) $(FLAGS) -I$(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	make -C ../libft
	ar rc $(NAME) $(OBJ)

clean:
	cd ../libft && make fclean
	rm -f $(OBJ)

fclean: clean
	make -C ../libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
