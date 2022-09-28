#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

int main(void)
{
	int	fd;

	fd = open("Makefile", O_RDONLY);
	for(int i = 0; i<80; i++)
	{
		printf("%s", get_next_line(fd));
	}
	close(fd);
	return (0);
}