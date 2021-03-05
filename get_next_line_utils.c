#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


char	*ft_strchr(const char *s, int c)
{
	while (*s != 0)
	{
		if (*s == (unsigned char)c)
			return ((char *)(s + 1));
		s++;
	}
	if (c == '\0' && *s == '\0')
		return ((char *)(s + 1));
	return (NULL);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*duplicate;

	i = 0;
	if (!src)
		return (0);
	duplicate = (char*)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (duplicate == NULL)
		return (0);
	while (src[i] != '\0')
	{
		duplicate[i] = src[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	i = 0;
	if (s_len - start < len)
		substring = (char *)malloc(sizeof(char) * (s_len - start + 1));
	else if (s_len < start)
		substring = (char *)malloc(sizeof(char) * (s_len + 1));
	else
		substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (i < len && i + start < ft_strlen(s))
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(s1))
		return (ft_strdup((char *)s2));
	joined_str = (char *)malloc((strlen(s1) + strlen(s2) + 1));
	if (joined_str == NULL)
		return (NULL);
	while (s1[i])
	{
		joined_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		joined_str[i + j] = s2[j];
		j++;
	}
	joined_str[i + j] = '\0';
	return (joined_str);
}


// int main()
// {
// 	char *s1;
// 	s1 = "HELLO";
//     printf("%s\n", ft_strjoin("", s1));
//     return 0;
// }
