#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

int main(void)
{
	int	fd;
	char *str;

	fd = open("Makefile", O_RDONLY);
	for(int i = 0; i<80; i++)
	{
		str = get_next_line(fd);
		//printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
}
