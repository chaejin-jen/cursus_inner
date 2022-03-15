//#include <stdio.h>
#include <limits.h>
#include "./include/ft_printf_bonus.h"

int	main(void)
{
	//long	long_n;

	//long_n = 147473649;
	//printf("%ld\n", long_n + 2147473649);
	//printf("%15p^\n", 2147473648);
	//printf("dsdsf%^\n", 2147473648);
	//printf("%+ i^\n", 2147473648);
	//printf("%0+14i^\n", -2147473648);
	//printf("%+.14i^\n", -2147473648);
	//printf("%0+14i^\n", 2147473648);
	//printf("%+.14i^\n", 2147473648);
	//printf("%.14i^\n", 2147473649);
	//printf("%+0.14i^\n", 2147473649);
	//printf("%+014i^\n", 2147473649);
	//printf("%014.2s^\n", "abcdefg");
	//printf("%d\n", printf("%014.2c^\n", 'a'));
	//printf("%d\n", printf("%6.5s^\n", 0));
	//printf("%-14s^\n", "abcdefg");
	//printf("printf(\"%%c\\n\", 1) : %d", printf("%c", 1));
	//#include "ft"

	ft_printf(" %-10s ", "abc");
	ft_printf(" %-10s ", "xyz");
	ft_printf(" %+d ", 0);
	ft_printf(" %+d ", -1);
	ft_printf(" %+d ", 9);
	ft_printf(" %+d ", 10);
	ft_printf(" %+d ", 11);
	ft_printf(" %+d ", 15);
	ft_printf(" %+d ", 16);
	ft_printf(" %+d ", 17);
	ft_printf(" %+d ", 99);
	ft_printf(" %+d ", 100);
	ft_printf(" %+d ", 101);
	ft_printf(" %+d ", -9);
	ft_printf(" %+d ", -10);
	ft_printf(" %+d ", -11);
	ft_printf(" %+d ", -14);
	ft_printf(" %+d ", -15);
	ft_printf(" %+d ", -16);
	ft_printf(" %+d ", -99);
	ft_printf(" %+d ", -100);
	ft_printf(" %+d ", -101);
	ft_printf(" %+d ", INT_MAX);
	ft_printf(" %+d ", INT_MIN);
	ft_printf(" %+d ", LONG_MAX);
	ft_printf(" %+d ", LONG_MIN);
	ft_printf(" %+d ", UINT_MAX);
	ft_printf(" %+d ", ULONG_MAX);
	ft_printf(" %+d ", 9223372036854775807LL);
	ft_printf(" %+d %+d %+d %+d %+d %+d %+d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %+i ", 0);
	ft_printf(" %+i ", -1);
	ft_printf(" %+i ", 1);
	ft_printf(" %+i ", 9);
	ft_printf(" %+i ", 10);
	ft_printf(" %+i ", 11);
	ft_printf(" %+i ", 15);
	ft_printf(" %+i ", 16);
	ft_printf(" %+i ", 17);
	ft_printf(" %+i ", 99);
	ft_printf(" %+i ", 100);
	ft_printf(" %+i ", 101);
	ft_printf(" %+i ", -9);
	ft_printf(" %+i ", -10);
	ft_printf(" %+i ", -11);
	ft_printf(" %+i ", -14);
	ft_printf(" %+i ", -15);
	ft_printf(" %+i ", -16);
	ft_printf(" %+i ", -99);
	ft_printf(" %+i ", -100);
	ft_printf(" %+i ", -101);
	ft_printf(" %+i ", INT_MAX);
	ft_printf(" %+i ", INT_MIN);
	ft_printf(" %+i ", LONG_MAX);
	ft_printf(" %+i ", LONG_MIN);
	ft_printf(" %+i ", UINT_MAX);
	ft_printf(" %+i ", ULONG_MAX);
	ft_printf(" %+i ", 9223372036854775807LL);
	ft_printf(" %+i %+i %+i %+i %+i %+i %+i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
}
