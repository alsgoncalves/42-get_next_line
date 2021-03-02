#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t catch;

	i = 0;
	j = 0;
	catch = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (needle[j] && haystack[i] == needle[j])
		{
			catch++;
			i++;
			j++;
		}
		if (j == ft_strlen(needle))
			return ((char *)haystack + (i - catch));
		i++;
	}
	return (NULL);
}

int		is_char_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*trimmed_str;

	start = 0;
	end = ft_strlen(s1);
	while (is_char_set(s1[start], set) && s1[start])
		start++;
	while (is_char_set(s1[end - 1], set) && end > start)
		end--;
	trimmed_str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (trimmed_str == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		trimmed_str[i] = s1[start];
		start++;
		i++;
	}
	trimmed_str[i] = '\0';
	return (trimmed_str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != 0)
	{
		if (*s == (unsigned char)c)
			return ((char *)s++);
		s++;
	}
	if (c == '\0' && *s == '\0')
		return ((char *)s++);
	return (NULL);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*duplicate;

	i = 0;
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

// int main()
// {
//     char *str;
//     str = "We are in 2021. And this year is going to be great and \n we are going\n to see our dreams come to live. It might \n";
//     printf("%s\n", ft_strchr(str, '\n'));
//     return 0;
// }