#include "minilibx-linux/mlx.h"
#include <stdlib.h>

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
	if (mlx == 0)
		return (1);

	mlx_destroy_display(mlx);
	free(mlx);
}
