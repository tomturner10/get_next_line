#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buf);
int		ft_strchr(char *str, int c);
char	*ft_strdup(char *str);
int		ft_strlen(char *s);

#endif