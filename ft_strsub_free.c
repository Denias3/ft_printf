#include "libft.h"
#include <stdlib.h>

char	*ft_strsub_free(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (size < start)
		return (NULL);
	i = 0;
	if (size < (size_t)start + len)
		str = (char*)malloc(sizeof(char) * (size + 1));
	else
		str = (char*)malloc(sizeof(char) * (len + 1));
	if (str != NULL)
	{
		while (i < len && s[start + i] != '\0')
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
	}
	free(s);
	return (str);
}
