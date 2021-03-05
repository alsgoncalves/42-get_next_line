#include "get_next_line.h"

int		save_line(char **storage, char **line)
{
	char *temporary;
	int len;

	len = 0;
	while ((*storage)[len] != '\0' && (*storage)[len] != '\n')
		len++;
	if (ft_strchr(*storage, '\n'))
	{
		*line = ft_substr(*storage, 0, len);
		temporary = ft_strdup(ft_strchr(*storage, '\n'));
		free(*storage);
		*storage = temporary;
		return (1);
	}
	else 
		return (0);
}

int get_next_line(int fd, char **line)
{
	static char *storage[1024];
	char *temporary;
	size_t bytes_read;
	char buffer[BUFFER_SIZE + 1];
	
	temporary = 0;

	if (read(fd, 0, 0) == -1 || !line || BUFFER_SIZE < 1 || fd < 0)
		return (-1);
	
	//buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char)); 

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{	
		buffer[bytes_read] = '\0';
		if (!storage[fd])
		{
			storage[fd] = ft_strdup(buffer);
		}
		else
		{
			temporary = storage[fd];
			storage[fd] = ft_strjoin(temporary, buffer);
			free(temporary);
		}
		if (save_line(&storage[fd], line))
		{
			return (1);
		}
	}	

	if ((bytes_read = read(fd, buffer, BUFFER_SIZE)) == 0 && !(storage[fd]))
	{
		*line = ft_strdup("");
		return 0;
	}
	if (!ft_strchr(storage[fd], '\n'))
	{
		*line = ft_strdup(storage[fd]);
		free(storage[fd]);
		storage[fd] = 0;
		return (0);
	}
	return 0;
}

// int main ()
// {
// 	int fd;
// 	char *line;
// 	//size_t bytes_read;

// 	fd = open("file.txt" , O_RDONLY);
// 	if(fd == -1)
// 	{
// 		printf("Error opening file");
// 		return (-1);
// 	}
// 	// bytes_read = read(fd, 0, "");
// 	// printf("bytes: %i\n", bytes_read);
	
// 	while (get_next_line(fd, &line))
// 	{
// 		printf("LINE: %s\n", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return(0);
// }