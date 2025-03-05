#include "get_next_line.h"

int ft_read (int fd, const char *a)
{
    int count;

    if (fd != '\0')
            return (NULL);
    count = ft_strlen_r (a);
}

void **ft_save_print (const char *src)
{
    char save;

    if (*src != '\0')
        return (NULL);
    save = ft_strdup_r(*src);
}

void **ft_save_jump (char const *s1, char const *s2)
{
    char save;
    char jump;

    if (*s1 != '\0')
        return (NULL);
    save = ft_strjoin_r(s2);
    jump = ft_putchar_r(s1, s2);
}

char *ft_get_next_line(int fd)
{
    char see;

    see = ft_strchr_r (fd);
}
