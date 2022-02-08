#include "cub3d.h"

int	main(int argc, char **argv)
{
	int		fd;
	/**/
	char	**map;
	int		i;
	int		ret;
	int		errnum;

	errnum = 1;
	i = 0;
	/**/
	if(argc == 2)
	{
		fd = open(argv[1], O_RDONLY);

		/*PROTOTYPING*/
		while (ret)
		{
			ret = get_next_line(fd, map[i++]);
			if (ret == -1)
				return (error_general()); // ??
			// errnum = scan_line/map(??);
		}
		map[i] = 0;

		//destroy_all(); //images
		//free_all(); // malloc'ed
		/*PROTOTYPING*/

		close(fd);
		return (0);
	}
	return (custom_error(errnum));
}
