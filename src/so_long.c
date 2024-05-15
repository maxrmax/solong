/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:05:24 by mring             #+#    #+#             */
/*   Updated: 2024/05/15 20:54:56 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>

#define WIDTH 1024
#define HEIGHT 1024

void	ft_error(void)
{
	printf("%s\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	mlx_t		*mlx;

	if (!param)
		return ;
	mlx = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(mlx);
		// system("ps aux | grep Music.app | awk '{print $2}' | awk 'NR==1 {print}' | xargs kill"); // EXTRA SOUND
	}
}

void	ft_loop_hook(void *param)
{
	mlx_t		*mlx;

	if (!param)
		return ;
	mlx = param;
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}
// int32_t	bg_image(mlx_t mlx, mlx_texture_t bg_image)
// {
// 	// bgimage = bg_image(mlx, texture);
// }

int32_t	main(void)
{
	// system("open -j -g /Users/mring/projects/solong/assets/sound/Parabola.mp3"); // EXTRA SOUND
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false);
	if (!mlx)
		ft_error();
	texture = mlx_load_png("./assets/background/Green_Nebula.png");
	if (!texture)
	{
		mlx_delete_texture(texture);
		ft_error();
	}
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image || mlx_image_to_window(mlx, image, 0, 0) < 0)
		ft_error();
	mlx_resize_image(image, WIDTH, HEIGHT);
	mlx_key_hook(mlx, ft_key_hook, mlx);
	mlx_loop_hook(mlx, ft_loop_hook, mlx);
	mlx_loop(mlx);
	return (0);
}

// void load_sprites(mlx_t *mlx, GameSprites *sprites, int tile_width, int tile_height) {
//     load_and_scale_sprite(mlx, &sprites->wall, "/Users/abhudulo/Desktop/c_projects/so_long_p/assets/sprites/rock_in_water_01.png", tile_width, tile_height);
//     load_and_scale_sprite(mlx, &sprites->collectible, "/Users/abhudulo/Desktop/c_projects/so_long_p/assets/sprites/Egg_item.png", tile_width, tile_height);
//     load_and_scale_sprite(mlx, &sprites->exit, "/Users/abhudulo/Desktop/c_projects/so_long_p/assets/sprites/Free_Chicken_House.png", tile_width, tile_height);
//     load_and_scale_sprite(mlx, &sprites->player, "/Users/abhudulo/Desktop/c_projects/so_long_p/assets/sprites/cat_0.png", tile_width, tile_height);
//     // Ensure you also load the floor sprite correctly
//     load_and_scale_sprite(mlx, &sprites->floor, "/Users/abhudulo/Desktop/c_projects/so_long_p/assets/sprites/Basic_Grass_Biom_things.png", tile_width, tile_height);
//     printf("All sprites loaded successfully.\n");
// }

/*
open, close, read, write,
malloc, free, perror,
strerror, exit

All functions of the math
library (-lm compiler option,
man man 3 math)

All functions of the MiniLibX

ft_printf and any equivalent
YOU coded
*/

// collect every collectible using the shortest route
// > shortest route from last collectible or helltaker like?
// wasd movement > up down left right 
// walls should be walls, duh
// amount of moves should be displayed in shell **
// 2D view (topdown or profile) zelda style
// doesn't have to be realtime (give inputs then let it calculate)
// can be any theme i want (textures etc)

// graphic has to be in a wndow
// window management has to be smooth
// esc must close window and quit in a clean way
// same with closing on [-][X]<-
// have to use images of MiniLibX

// map: walls(1), collectibles(C), freespace(0), exit(E), spawnpoint(P)
// has to contain P, E and at least one C
// no duplicate P, E
// must be a closed map (1) else error
// check for valid path
// parse any map as long the rules are respected
// if map is wrong, clean exit
// return Error\n, followed by my own explicit message

// BONUS:
// lose if you touch Enemy patrol
// sprite animation
// movement count on screen instead of the shell
