/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:05:24 by mring             #+#    #+#             */
/*   Updated: 2024/05/14 18:54:00 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>

#define WIDTH 512
#define HEIGHT 512

int32_t main(void)
{
	mlx_t		*mlx;
	xpm_t		*xpm;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		return (1);
	xpm = mlx_load_xpm42("./assets/space_background.xpm");
	printf("1\n");
	if (!xpm)
		return (1);
	img = mlx_texture_to_image(mlx, &xpm->texture);
	printf("2\n");
	if (!img)
		return (1);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		return (1);
	mlx_loop(mlx);
	printf("3\n");
	mlx_delete_image(mlx, img);
	printf("4\n");
	mlx_delete_xpm42(xpm);
	printf("5\n");
	mlx_terminate(mlx);
	printf("6\n");
	return (0);
}

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
