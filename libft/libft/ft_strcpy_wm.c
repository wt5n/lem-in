#include "libft.h"

char	*ft_strcpy_wm(char *str)
{
	char *res;

	res = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	res = ft_strcpy(res, str);
	return (res);
}