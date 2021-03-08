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
		temporary = ft_strdup(ft_strchr(*storage, '\n') + 1);
		free(*storage);
		*storage = temporary;
		return (1);
	}
	else 
		return 0;
}

void		store_and_print(char **storage, char *buffer)
{ 
	char *temporary;

	temporary = 0;
	if (!(*storage))
		*storage = ft_strdup(buffer);
	else
	{
		temporary = *storage;
		*storage = ft_strjoin(temporary, buffer);
		free(temporary);
	}
}

int get_next_line(int fd, char **line)
{
	static char *storage[1024];
	size_t bytes_read;
	char buffer[BUFFER_SIZE + 1];
	
	if (read(fd, 0, 0) == -1 || !line || BUFFER_SIZE < 1 || fd < 0)
		return (-1);
	
	if (storage[fd] && save_line(&storage[fd], line))
		return (1);

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{	
		buffer[bytes_read] = '\0';
		store_and_print(&storage[fd], buffer);
		if (save_line(&storage[fd], line))
			return (1);
	}	
	if (storage[fd] && !ft_strchr(storage[fd], '\n'))
	{
		*line = ft_strdup(storage[fd]);
		free(storage[fd]);
		storage[fd] = 0;
		return (0);
	}
	if ((bytes_read = read(fd, buffer, BUFFER_SIZE)) == 0 && !(storage[fd]))
		*line = ft_strdup("");
	return 0;
}

// int main ()
// {
// 	int fd;
// 	char *line;
// 	//size_t bytes_read;

// 	fd = open("gnlTester/files/alternate_line_nl_no_nl" , O_RDONLY);
// 	if(fd == -1)
// 	{
// 		printf("Error opening file");
// 		return (-1);
// 	}
// 	while (get_next_line(fd, &line))
// 	{
// 		printf("LINE: %s\n", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return(0);
// }