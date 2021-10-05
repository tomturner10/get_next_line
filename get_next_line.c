#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *buf;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL || fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	printf("%lu", sizeof(char));
	return (NULL);
}

int	main(void)
{
	FILE *fd = fopen("test.txt", "r");
	get_next_line(fileno(fd));
}