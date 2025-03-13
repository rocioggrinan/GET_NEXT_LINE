#include "get_next_line.h"

int	ft_strlen_r(const char *a)
{
	int	count;

	count = 0;
	if (!a)
		return (0);
	while (a[count])
		count++;
	return (count);
}
char	*ft_substr_r(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*b;
	size_t	i;

	if (s == 0)
		return (0);
	i = 0;
	a = ft_strlen_r(s);
	if (start >= a)
		return ((char *)ft_strdup_r(""));
	else if (a - start <= len)
		len = a - start;
	b = (char *)malloc(sizeof(char) * (len + 1));
	if (b == 0)
		return (0);
	while (i < len)
	{
		b[i] = s[i + (size_t)start];
		i++;
	}
	b[i] = '\0';
	return (b);
}
char	*ft_strdup_r(const char *src)
{
	int		len;
	char	*tab;
	int		i;

	i = 0;
	len = ft_strlen_r((char *)src);
	tab = (char *)malloc(sizeof(char) * len + 1);
	if (tab == 0)
		return (0);
	while (i < len)
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
char	*ft_strjoin_r(char const *s1, char const *s2)
{
	char	*b;
	int		count;
	int		a;
	int		c;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen_r(s1);
	c = ft_strlen_r(s2);
	count = 0;
	b = (char *)malloc(sizeof(char) * (a + c + 1));
	if (!b)
		return (NULL);
	while (s1[count] != '\0')
	{
		b[count] = s1[count];
		count++;
	}
	while (s2[count - a] != '\0')
	{
		b[count] = s2[count - a];
		count++;
	}
	b[count] = '\0';
	return (b);
}

char	*ft_strchr_r(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}