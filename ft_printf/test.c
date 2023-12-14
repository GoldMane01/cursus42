#include "ft_printf.h"

#include <stdio.h>

int main(void)
{
	char *s = "cccc";
	char *p = "ennove";
	ft_printf("numero: %d\nstring: %s\nporcentaje: %%\npuntero: %p\n", 12344, p, s);
	return (0);
}