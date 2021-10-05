#include "get_next_line.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	destlen;
	size_t	srclen;

	j = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	while (j + destlen < dstsize - 1 && src[j] != '\0' && dstsize != 0)
	{
		dest[destlen + j] = src[j];
		j++;
	}
	dest[destlen + j] = '\0';
	if (destlen >= dstsize)
		destlen = dstsize;
	return (destlen + srclen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*rtn;
	unsigned int	s1len;
	unsigned int	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	rtn = (char *)malloc((s1len + s2len) * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	ft_strlcpy(rtn, (char *)s1, s1len + 1);
	ft_strlcat(rtn, s2, s1len + s2len + 1);
	return (rtn);
}