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
	printf("Return value of printf: %d\nReturn value of ft_printf: %d\n\n", i, j);

	printf("Paco Test 10:\n");
	i = printf(" NULL %s NULL \n", NULL);
	j = ft_printf(" NULL %s NULL \n", NULL);
	printf("Return value of printf: %d\nReturn value of ft_printf: %d\n\n", i, j);

 
	//hex
	printf("Paco Test 10:\n");
	i = printf(" %x \n", 99);
	j = ft_printf(" %x \n", 99);
	printf("Return value of printf: %d\nReturn value of ft_printf: %d\n\n", i, j);

	printf("Paco Test 1:\n");
	i = printf(" %x \n", 0);
	j = ft_printf(" %x \n", 0);
	printf("Return value of printf: %d\nReturn value of ft_printf: %d\n\n", i, j);

 
	//error
	printf("Test error because of wrong specifier:\n");
	char *test = "Hello, world!";
	i = printf(" %d \n", test);
	j = ft_printf(" %d \n", test);
	int k;
	k = dprintf(" %d \n", test);
	printf("Return value of printf: %d\nReturn value of ft_printf: %d\nReturn value of dprintf: %d\n\n", i, j, k);

	return (0);
}
