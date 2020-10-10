#include "libft/libft.h"

int main()
{
//	int t[5] = {5, 2, 1, 2, 5};
//	int k[5] = {0};
	char m[5] = "Hello";
	char d[5] = {0};
//	ft_memcpy(k, t, 5);
	ft_memcpy(d, m, 5);
//	for (int i = 0; i < 5; i++)
//		printf("%d ", k[i]);
//	printf("\n");
//	for (int i = 0; i < 5; i++)
//		printf("%d ", t[i]);
	printf("\n");
	printf("%s\n", m);
	printf("%s\n", d);
	return 0;
}