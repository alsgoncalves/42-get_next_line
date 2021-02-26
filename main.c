#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		get_next_line(int fd, char **line)
{
	
}

int main()
{
    int fd;
	int bytes_read;
	char *str;

	
	str = (char *)malloc(100 * sizeof(char));

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error while opening file.");
		exit(0);
	}

	if ((bytes_read = read(fd, str, BUFFER_SIZE)))
	{
		printf("%s\n", str);
		while (!strchr(str, '\n'))
		[

		]
	}	

	free(str);	

	if (close(fd) < 0)
	{
		printf("Error while closing file");
		exit(0);
			
	}
    return 0;
}