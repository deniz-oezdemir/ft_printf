#include "ft_printf.h"

#include <stdio.h>
int	main(void)
{
	//string
	int	i;
	int	j;
	printf("Test 3:\n");
	char str[] = "friend";
	i = printf("hello, %s.\n", str);
	j = ft_printf("hello, %s.\n", str);
	printf("Return value of printf: %d\nReturn value of ft_printf: %d\n", i, j);
	return (0);
}
