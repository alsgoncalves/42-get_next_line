#include "get_next_line.h"

int		check_for_new_line(char *str)
{
   while (*str)
   {
	   if (*str == '\n')
	   		return (1);
	   str++;
   }
   return 0;
}

// char	*read_lines(int fd)
// {
// 	char *read_lines;
// 	int bytes_read;

// 	read_lines = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
// 	bytes_read = 0;
// 	bytes_read = read(fd, read_lines, BUFFER_SIZE + 1);
// 	read_lines[bytes_read] = '\0';
// 	if (bytes_read == 0)
// 		return 0;
// 	return (read_lines);
// }

// int		save_line(char *storage, char *lines_after_n, char **line)
// {
// 	lines_after_n = ft_strchr(storage, '\n');
// 	*line = ft_substr(storage, 0, (ft_strlen(storage) - ft_strlen(lines_after_n) - 1));
// 	free(storage);
// 	storage = ft_strdup(lines_after_n);
// 	return (1);
// }

int get_next_line(int fd, char **line)
{
	static char *storage;
	char *lines_after_n;
	char *temporary;
	size_t bytes_read;
	char buffer[BUFFER_SIZE + 1];
	
	temporary = 0;
	lines_after_n = 0;

	if (read(fd, 0, 0) == -1 || !line || BUFFER_SIZE < 1)
		return (-1);
	
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (!storage)
			storage = ft_strdup("");
		temporary = ft_strjoin(storage, buffer);
		free(storage);
		storage = temporary;
		if (check_for_new_line(storage) == 1)
		{
			lines_after_n = ft_strchr(storage, '\n');
			*line = ft_substr(storage, 0, (ft_strlen(storage) - ft_strlen(lines_after_n) - 1));
			free(storage);
			storage = ft_strdup(lines_after_n);
			return (1);
			//return (save_line(storage, lines_after_n, line));
		}
	}	
	if ((bytes_read = read(fd, buffer, BUFFER_SIZE)) == 0)
	{
		if (storage)
		{
			*line = ft_strdup(storage);
			free(storage);
			storage = 0;
			return (1);
		}
		else 
		{
			*line = ft_strdup("");
			return 0;
		}
	}
	if ((bytes_read = read(fd, buffer, BUFFER_SIZE)) < 0)
		return (-1);
	return 0;
}

int main ()
{
	int fd;
	char *line;
	//size_t bytes_read;

	fd = open("file.txt" , O_RDONLY);
	if(fd == -1)
	{
		printf("Error opening file");
		return (-1);
	}
	// bytes_read = read(fd, 0, "");
	// printf("bytes: %i\n", bytes_read);
	
	while (get_next_line(fd, &line))
	{
		printf("LINE: %s\n", line);
		free(line);
	}
	close(fd);
	return(0);
}