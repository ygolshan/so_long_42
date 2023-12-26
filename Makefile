# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 16:11:17 by ygolshan          #+#    #+#              #
#    Updated: 2023/05/28 14:29:34 by ygolshan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC =  cc
CFLAGS = -Wall -Werror -Wextra
SRCS = srcs/main.c srcs/basicmap.c \
		srcs/check.c srcs/path.c srcs/queue.c \
		srcs/free.c srcs/image.c srcs/position.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -O3 -c $< -o $@

$(NAME): $(OBJS)

	$(MAKE) -C mlx 2> logs
	rm -f logs
	cd ./printf && make
	$(CC) $(CFLAGS) -I mlx/libmlx.a -Imlx -Lmlx -lmlx -framework OpenGL \
	-framework AppKit ./libft/libft.a ./printf/libftprintf.a -o $(NAME) $(OBJS)
	

	
clean:
	cd ./printf && make fclean
	-rm -f $(OBJS)
	-rm -f mlx/*.o

fclean: clean
	make -C ./printf fclean
	rm -f $(NAME)
	rm -f mlx/libmlx.a

re: fclean all

.PHONY: fclean clean re all
