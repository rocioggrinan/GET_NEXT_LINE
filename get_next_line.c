#include "get_next_line.h"

static char	*ft_read_buffer(int fd, char *buffer)
{
	char	*buffer_temp;
	int		bytes_read;

	bytes_read = 1;
	if (!buffer)
		buffer = ft_strdup_r("");
	buffer_temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer_temp)
		return (free(buffer), NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer_temp, BUFFER_SIZE);
		printf("buffer contiene: %s\n", buffer); //
		if (bytes_read == -1)
		{
			return (free(buffer_temp), free(buffer), NULL);
		}
		buffer_temp[bytes_read] = '\0';
		buffer = ft_strjoin_r(buffer, buffer_temp);
		if (ft_strchr_r(buffer_temp, '\n'))
			break ;
	}
	free(buffer_temp);
	return (buffer);
}
static char	*ft_sacline(char *buffer_acu)
{
	int		count;
	char	*line;

	count = 0;
	if (!buffer_acu)
	{
		free(buffer_acu);
		buffer_acu = NULL;
		return (NULL);
	}
	while (buffer_acu[count] && buffer_acu[count] != '\n')
		count++;
	line = ft_substr_r(buffer_acu, 0, count + 1);
	return (line);
}
static char	*ft_delet(char *buffer_acu)
{
	int		i;
	char	*new;

	i = 0;
	if (!buffer_acu)
	{
		free(buffer_acu);
		buffer_acu = NULL;
		return (NULL);
	}
	while (buffer_acu[i] != '\n' && buffer_acu[i] != '\0')
		i++;
	new = ft_substr_r(buffer_acu, i + 1, ft_strlen_r(buffer_acu) - i);
	if (!new)
	{
		free(buffer_acu);
		return (NULL);
	}
	free(buffer_acu);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buffer_read;
	char		*line;

	/*     if (!buffer_read) // si falla la lectura
			return (NULL); */
	buffer_read = ft_read_buffer(fd, buffer_read);
	line = ft_sacline(buffer_read); // sacar la linea //mi funcion
	if (!line)
		return (free(buffer_read), buffer_read = NULL); // si falla
	buffer_read = ft_delet(buffer_read);
	if (line && *line == '\0') // si falla algo
	{
		free(line);        // liberamos todo
		free(buffer_read); // ponemos a null la cajita
		buffer_read = NULL;
		return (NULL); // devolvemos null
	}
	return (line); // return line
}
/*int main(void)
{
	int fd;
	char *line;
	int line_number = 1;

	fd = open("test.txt", O_RDONLY);


	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Línea %d: %s", line_number, line);
		free(line);
		line_number++;
	}

	close(fd);
	printf("Lectura terminada. Total de líneas: %d\n", line_number - 1);
	return (0);
}*/
