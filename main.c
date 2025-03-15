#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd_1;
	int		i;
	char	*line[4096];

	i = 1;
	fd_1 = open("empty.txt", \
					O_RDONLY);
	while (1)
	{
		line[fd_1] = get_next_line(fd_1);
		printf("Line %d for fd %d: %s\n", i, fd_1, line[fd_1]);
		if (!line[fd_1])
			return (0);
		free(line[fd_1]);
		i++;
	}
}