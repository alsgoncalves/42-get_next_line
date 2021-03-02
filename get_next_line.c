
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

int get_next_line(int fd, char **line) 
{
	static char *storage;
	int bytes_read;
	char *line_len;
	char *read_lines;
	//char *tmp;
	
	// if (*line != NULL)
	// {
	// 	free(*line);
	// 	*line = NULL;
	// }
	
	if (storage <= 0)
	{
		read_lines = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
		bytes_read = 0;
		bytes_read = read(fd, read_lines, BUFFER_SIZE + 1);
		read_lines[bytes_read] = '\0';
		storage = ft_strdup(read_lines);
		if (check_for_new_line(read_lines) == 1)
		{	
			
			line_len = ft_strchr(storage, '\n');
			
			printf("Line_len: %s\n", line_len);
			
			*line = ft_substr(storage, 0, (ft_strlen(storage) - ft_strlen(line_len)));
			printf("Storage: %s\n", storage);
			storage = line_len;
			
			
			printf("Line: %s\n", *line);
			free(*line);
			return (1);
		}
	}
	else 
	{
		printf("SECOND LOOP Storage: %s\n", storage);
		line_len = ft_strchr(storage, '\n');
			
		printf("Line_len: %s\n", line_len);
		
		*line = ft_substr(storage, 0, (ft_strlen(storage) - ft_strlen(line_len)));
		printf("Storage: %s\n", storage);
		storage = line_len;
		
		
		printf("Line: %s\n", *line);
		free(*line);
		return (1);
	}
	return 0;
}

int main () 
{
   int fd;
   char *line;

   /* opening file for reading */
   fd = open("file.txt" , O_RDONLY);
   if(fd == -1) {
      printf("Error opening file");
      return (-1);
   }
   
   get_next_line(fd, &line);
   get_next_line(fd, &line);

   close(fd);
   
   return(0);
}