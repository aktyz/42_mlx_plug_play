#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>

#define WIDTH			400
#define HEIGHT			400
#define MALLOC_ERROR	1

typedef struct s_mlx_data
{
	void	*mlx_serv;
	void	*mlx_wind;
}	t_mlx_data;

int	handle_input(int keysym, t_mlx_data *data);

int	main(void)
{
	t_mlx_data	data;

	data.mlx_serv = mlx_init();
	if (data.mlx_serv == 0)
		return (MALLOC_ERROR);

	data.mlx_wind = mlx_new_window(data.mlx_serv, HEIGHT, WIDTH, "My window");
	if (data.mlx_wind == 0)
	{
		mlx_destroy_display(data.mlx_serv);
		free(data.mlx_serv);
		return (MALLOC_ERROR);
	}
	mlx_key_hook(data.mlx_wind, handle_input, &data);
	mlx_loop(data.mlx_serv);
	return (0);
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(data->mlx_serv, data->mlx_wind);
		mlx_destroy_display(data->mlx_serv);
		free(data->mlx_serv);
		return (1);
	}
	printf("The %d key has been pressed\n\n", keysym);
	return (0);
}
