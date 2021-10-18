#include "get_next_line.h"

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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0' )
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*rtn;
	unsigned int	s1len;
	unsigned int	s2len;

	s1len = 0;
	s2len = 0;
	rtn = (char *)malloc((s1len + s2len) * sizeof(char));
	while (s1[s1len] != '\0')
		s1len++;
	while (s2[s2len] != '\0')
		s2len++;
	if (rtn == NULL)
		return (NULL);
	ft_strlcpy(rtn, (char *)s1, s1len + 1);
	ft_strlcat(rtn, s2, s1len + s2len + 1);
	return (rtn);
}

char	*ft_strdup(const char *s1)
{
	char			*str;
	unsigned int	s1len;

	s1len = 0;
	while (s1[s1len] != '\0')
		s1len++;
	str = (char *)malloc((s1len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, (char *)s1, s1len + 1);
	return (str);
}