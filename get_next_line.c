
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

char	*read_lines(int fd)
{
	char *read_lines;
	int bytes_read;

	read_lines = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	bytes_read = 0;
	bytes_read = read(fd, read_lines, BUFFER_SIZE + 1);
	read_lines[bytes_read] = '\0';
	if (bytes_read == 0)
		return 0;
	return (read_lines);
}

int get_next_line(int fd, char **line) 
{
	static char *storage;
	char *line_len;
	char *temporary;
	char *lines_read;
	
	// if (*line != NULL)
	// {
	// 	free(*line);
	// 	*line = NULL;
	// }
	
	if (storage <= 0)
		storage = ft_strdup(read_lines(fd));
	if (check_for_new_line(storage) == 1)
	{	
		line_len = ft_strchr(storage, '\n');
		*line = ft_substr(storage, 0, (ft_strlen(storage) - ft_strlen(line_len)));
		storage = ft_substr(line_len, 1, ft_strlen(line_len) - 1);
		//free(*line);
		return (1);
	}
	else 
	{
		while(check_for_new_line(storage) == 0)
		{
			lines_read = read_lines(fd);
			temporary = ft_strjoin(storage, lines_read);
			free(storage);
			storage = temporary;
		}
		if (check_for_new_line(storage) == 1)
		{	
			line_len = ft_strchr(storage, '\n');
			*line = ft_substr(storage, 0, (ft_strlen(storage) - ft_strlen(line_len)));
			storage = ft_substr(line_len, 1, ft_strlen(line_len) - 1);
			//free(*line);
			return (1);
		}
	}
	return 0;
}

int main () 
{
	int fd;
	char *line;
	
	fd = open("file.txt" , O_RDONLY);
	if(fd == -1)
	{
		printf("Error opening file");
		return (-1);
	}
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return(0);
}