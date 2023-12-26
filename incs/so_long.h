/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:56:25 by ygolshan          #+#    #+#             */
/*   Updated: 2023/05/28 15:14:02 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include<mlx.h>
# include<fcntl.h>
# include<unistd.h>
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<string.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*imgs[8];
	int		cont;
	int		exit;
	int		movements;
}	t_game;
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;
typedef struct s_mem
{
	char	**map;
	int		map_len;
	int		exit;
	int		entry;
	int		collect;
	int		*c_pos;
	int		e_pos[2];
	int		p_pos[2];
	t_game	*game;
}	t_mem;
typedef struct s_node
{
	int				i;
	int				j;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;
typedef struct s_queue
{
	t_node	*first;
	t_node	*last;
}	t_queue;
void	end_game(t_game *game);
int		close_window(int keycode, void *param);
void	initialize_game(t_game *game);
void	create_window(t_game *game, int width, int height);
void	setup_game(t_mem *mem);
int		save_map(char *map_addr, t_mem *mem);
void	print_map(char **map);
int		check_map_validity(t_mem *mem);
int		save_map(char *map_addr, t_mem *mem);
int		check_path(t_mem *mem, int i, int j);
t_queue	*create_queue_node(void);
t_node	*create_node_element(int i, int j);
void	enqueue_node(t_queue *queue, t_node *node);
void	dequeue_node(t_queue *queue);
void	free_queue(t_queue *queue);
void	cleanup_memory(t_mem *mem, int on_off);
int		handle_exit(t_mem *mem);
int		render_map(t_game *game, char **map);
int		key_hook(int keycode, void *param);
#endif
