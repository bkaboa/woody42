#include "../../hdr/woody.h"

int8_t
ft_strcmp(const char *str1, const char *str2)
{
	char *tmpstr1 = (char*)str1;
	char *tmpstr2 = (char*)str2;

  if (str1 == NULL && str2 == NULL)
    return (0);
  if (str1 == NULL || str2 == NULL)
    return (1);

	while (*tmpstr1 && *tmpstr2 && *tmpstr1 == *tmpstr2) {
		tmpstr1++;
		tmpstr2++;
	}

  if (*tmpstr1 == 0)
    return (*tmpstr2);
  if (*tmpstr2 == 0)
    return (*tmpstr1);
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == 0 || s2[i] == 0)
			return (0);
		i++;
	}
	return (0);
}

size_t  ft_strlen(char *str)
{
    char *tmp = str;
    if (!tmp)
        return (0);
    tmp = str;
    while (*tmp)
        ++tmp;
    return (tmp - str);
    
}

void ft_memset(void *ptr, const u_int8_t data, size_t lenght)
{
  u_int8_t *strPtr = (u_int8_t*)ptr;

  while (lenght-- > 0)
    *strPtr++ = data;
}

