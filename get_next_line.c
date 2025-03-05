#include "get_next_line.h"
/*
static int ft_read (int fd, const char *a)
{
    int count;

    if (fd != '\0')
            return (NULL);
    count = ft_strlen_r (a);
}

static void **ft_save_print (const char *src)
{
    char save;

    if (*src != '\0')
        return (NULL);
    save = ft_substr_r (*src);
}

static void **ft_save_jump (char const *s1, char const *s2)
{
    char save;
    char jump;

    if (*s1 != '\0')
        return (NULL);
    save = ft_strjoin_r(s2);
    jump = ft_putchar_r(s1, s2);
}*/
static char *ft_sacline(char *buffer)
{
    int count;
    char *line;

    count = 0;
    if (!buffer)
        return(NULL);
    while (buffer[count] && buffer[count] != '\n')
        count++;
    line = ft_substr_r(buffer, 0, count + 1);
    return (line);
}

char *get_next_line(int fd)
{
    static char *buffer;
    int bytes_read;

    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read <= 0)
        return (NULL);
    buffer[bytes_read] = '\0';
    ft_sacline(buffer);
    char *line = ft_sacline(line);
    printf("aqui: %s\n",line);

    return (buffer);
}
int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line = get_next_line(fd);
    printf("Leído: %s\n", line);
    close(fd);
    return (0);
}