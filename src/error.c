#include "cub3d.h"

int	error_general(void)
{
	perror(strerror(errno));
	return (errno);
}
