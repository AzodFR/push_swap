#include "checker.h"

char	*ft_strchr(char *s, char c)
{
	int		i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return ((char *)&s[i]);
	return (NULL);
}


char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

char	*ft_strdup(char *s)
{
	char	*ptr;
	int		i;

	i = -1;
	if (!(ptr = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	while (s[++i])
		ptr[i] = s[i];
	ptr[i] = 0;
	return (ptr);
}

char	*ft_substr(char *str, unsigned int start, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;
	char			*newstr;

	i = 0;
	j = ft_strlen(str);
	if (start >= j || j == 0)
		return (ft_strdup(""));
	count = start - j;
	if (count > len)
		count = len;
	if (!(newstr = malloc((count + 1) * sizeof(char))))
		return (NULL);
	while (len--)
		newstr[i++] = str[start++];
	newstr[i] = 0;
	return (newstr);
}