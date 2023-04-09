/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:16:29 by crepou            #+#    #+#             */
/*   Updated: 2023/04/09 21:56:00 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include "gnl/get_next_line.h"
# include "printf/ft_printf.h"
# include <fcntl.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# define WIDTH 1024
# define HEIGHT 1024

typedef enum type
{
	C = 0,
	E = 1,
	G = 2,
	W = 3,
	P = 4,
	B = 5,
}			t_type;

typedef struct map_info
{
	int			co_x;
	int			co_y;
	int			empty_space;
	int			walls;
	int			collectibles;
	int			exits;
	int			position;
	int			player_x;
	int			player_y;
	int			score;
	int			exit_enabled;
	int			enemy_x;
	int			enemy_y;
	int			enemies;
	int			win;
	mlx_image_t	*score_img;
	int32_t		fire;
	float		fire_x;
	float		fire_y;
	float		fire_stop;
}			t_map_info;

typedef struct coordinates
{
	int				x;
	int				y;
	char			val;
	int				instance_index;
	int				size;
}			t_coordinates;

typedef struct lines_table
{
	t_coordinates		**points;
	struct lines_table	*next;
}			t_lines_table;

typedef struct map
{
	t_lines_table	*lines_table;
	t_map_info		*map_info;
}			t_map;

typedef struct line_info
{
	int	length;
	int	empty_space;
	int	walls;
	int	collectibles;
	int	exits;
	int	position;
	int	enemies;
	struct line_info *next;
}			t_line_info;

typedef struct system
{
	t_map		*map;
	mlx_t		*window;
	mlx_image_t	**images;
}			t_system;

void			not_valid_arguments(void);
char			*so_long(int fd);
char			*not_valid_map(t_system *system);
void			not_valid_fd(void);
mlx_t			*create_window(int width, int height);
char			*window_creation_error(t_system *system);
char			*system_struct_error(void);
mlx_image_t		*create_player(mlx_t *mlx);
mlx_image_t		*create_ground(mlx_t *mlx);
mlx_image_t		*create_wall(mlx_t *mlx);
mlx_image_t		*create_enemy(mlx_t *mlx);
int				check_map(t_map *mp);
t_line_info		*create_line_info(void);
t_line_info		*read_line(char	*line);
t_map			*read_map(int fd);
t_map			*create_map(void);
t_coordinates	**create_line_table(int line_no, char *curr_line, t_map *map);
t_lines_table	*create_new_table_line(\
	t_coordinates **table_line, t_lines_table *head);
int				check_top(t_map *map);
int				check_bottom(t_map *map);
int				check_left(t_map *map);
int				check_right(t_map *map);
int				validate_up(t_map *mp, int x, int y);
int				validate_down(t_map *mp, int x, int y);
int				validate_left(t_map *mp, int x, int y);
int				validate_right(t_map *mp, int x, int y);
char			*draw_window_error(void);
mlx_t			*draw_map_on_window(mlx_t	*window, \
					t_map	*map, mlx_image_t	**images);
mlx_image_t		*create_collectible(mlx_t *mlx);
mlx_image_t		*create_exit(mlx_t *mlx);
mlx_image_t		**create_images(mlx_t *window);
mlx_t			*draw_element(t_coordinates *elem, \
					mlx_t *window, mlx_image_t **images);
void			quit_window(mlx_key_data_t keydata, t_system *system);
t_type			get_enum_from_char(char c);
void			set_image_to_window(mlx_t *window, \
					mlx_image_t *image, int depth, t_coordinates elem);
void			move_left(mlx_key_data_t keydata, t_system *system);
t_coordinates	*elem_identify(t_map *map, int x, int y);
void			move_right(mlx_key_data_t keydata, t_system *system);
void			move_up(mlx_key_data_t keydata, t_system *system);
void			move_down(mlx_key_data_t keydata, t_system *system);
void			update_elem_value(t_map	**map, char updated_value, \
					int x, int y);
void			move_over_empty_space(t_system *system, int type, int x, int y);
void			move_over_collectible(t_system *system, int type);
int				update_map(t_map **map, t_line_info *curr_ln_info, \
					char *curr_ln, int ln_no);
void			free_coordinates(t_coordinates **coordinates);
void			free_lines_table(t_lines_table *lines);
void			free_all(t_system *system);
char			*create_images_error(void);
void			free_images(mlx_image_t **images, mlx_t *window);
mlx_image_t		*create_terrain(mlx_t *mlx);
void			shot_fire(mlx_key_data_t keydata, t_system *system);
t_coordinates	*next_wall(int x, int y, t_system *system);
mlx_image_t		*create_fire(mlx_t *mlx);
int				all_are_reachable(t_map *mp, int x, int y);
void			flood_fill(char ***map, int x, int y, t_map *mp);
int				has_element(char **map, int x, int y, char type);
void			fire_graphic(t_system *system);
char			**create_array_map(t_map *mp);
void			free_array_map(char ***map, t_map *mp);
t_coordinates	**fill_lines_table(t_coordinates ***table, \
					char *curr_line, t_map *map, int line_no);
int				walls_in_position(t_map *mp);
int				get_first_line(t_map **map, char **curr_line, int fd);
void			delete_enemy(t_system *system);
#endif