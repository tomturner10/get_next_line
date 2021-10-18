#include "get_next_line.h"


static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	*ft_append(char *line, char *buf)
{
	if (line == NULL)
		return (ft_strdup(buf));
	else
		return (ft_strjoin(line, buf));
}

static char	*ft_trim(char *line)
{
	char *rtn;
	int i;

	i = 0;
	if (line == NULL || line[0] == '\0')
		return (NULL);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	rtn = (char *)malloc((i + 1) * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	rtn[i] = '\0';
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		rtn[i] = line[i];
	return (rtn);
}

static char	*ft_overwrite(char *line)
{
	char	*rtn;
	int i;
	int j;

	i = 0;
	j = 0;
	if (ft_strchr(line, '\n') == 0)
	{
		free(line);
		return (NULL);
	}
	rtn = (char *)malloc((ft_strlen(line) + 1) * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	while (line[i] != '\n')
		i++;
	i++;
	while (i + j < ft_strlen(line) && line[i + j] != '\0')
	{
		rtn[j] = line[i = j];
		j++;
	}
	rtn[j] = '\0';
	free(line);
	return (rtn);
}

char	*get_next_line(int fd)
{
	char *line;
	char *buf;
	int r;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL || fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	r = 1;
	while (ft_strchr(line, '\n') == 0 && r != 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			break;
		buf[r] = '\0';
		line = ft_append(line, buf);
	}
	free(buf);
	buf = ft_trim(line);
	line = ft_overwrite(line);
	return (buf);
}

int	main(void)
{
	FILE *fd = fopen("test.txt", "r");
	get_next_line(fileno(fd));
}