#include "cub3d.h"

int	main(int argc, char **argv)
{
	int	fd;

	if(argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		return (0);
	}
	return (1);
}