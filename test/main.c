#include <stdio.h>
#include "../ft_printf.h"
#include "../libft/libft.h"
#include <limits.h>

void float_checker()
{
	// int i = 0;
	int a;
	int b;
	int i = 0;
	a = ft_printf("my: %f|\n", 1.00);
	b = b = printf("og: %f|\n", 1.00);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %f|\n", 32.23);
	b = printf("og: %f|\n", 32.23);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %.5f|\n", 122.358);
	b = printf("og: %.5f|\n", 122.358);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %f|\n", -52.9);
	b = printf("og: %f|\n", -52.9);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %f|\n", -9.88);
	b = printf("og: %f|\n", -9.88);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %f|\n", 78.221);
	b = printf("og: %f|\n", 78.221);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %.0lf|\n", 99999999.1213);
	b = printf("og: %.0lf|\n", 99999999.1213);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %f|\n", 0.1223);
	b = printf("og: %f|\n", 0.1223);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %3.f|\n", 42.123312);
	b = printf("og: %3.f|\n", 42.123312);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %f|\n", 10.01010101);
	b = printf("og: %f|\n", 10.01010101);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %f|\n", 0.0000);
	b = printf("og: %f|\n", 0.0000);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	double ff = 89.999;
	a = ft_printf("my: %.f|\n", ff);
	b = printf("og: %.f|\n", ff);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %.2f|\n", 189.999);
	b = printf("og: %.2f|\n", 189.999);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %.2f|\n", 9.9999999);
	b = printf("og: %.2f|\n", 9.9999999);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %.f|\n", 9.9999999);
	b = printf("og: %.f|\n", 9.9999999);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %.f|\n", 999999.99);
	b = printf("og: %.f|\n", 999999.99);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %5.1f|\n", 999999.99);
	b = printf("og: %5.1f|\n", 999999.99);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %.2f|\n", 999999.99);
	b = printf("og: %.2f|\n", 999999.99);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	ft_printf("\n");
	a = ft_printf("my: %.2f|\n", 9.9999999);
	b = printf("og: %.2f|\n", 9.9999999);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %.f|\n", 9.9999999);
	b = printf("og: %.f|\n", 9.9999999);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %.4f|\n", 3.3399999);
	b = printf("og: %.4f|\n", 3.3399999);
	printf("%d)  %d - %d\n\n", i++,  a, b);


	a = ft_printf("my: %+010.4f|\n", 3.3399999);
	b = printf("og: %+010.4f|\n", 3.3399999);
	printf("%d)  %d - %d\n\n", i++,  a, b);


	a = ft_printf("my: %+10.4f|\n", 3.3399999);
	b = printf("og: %+10.4f|\n", 3.3399999);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %10.4f|\n", -3.3399999);
	b = printf("og: %10.4f|\n", -3.3399999);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: % 010.4f|\n", -3.3399999);
	b = printf("og: % 010.4f|\n", -3.3399999);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: % 010.4f|\n", 3.3399999);
	b = printf("og: % 010.4f|\n", 3.3399999);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: % 10.4f|\n", 3.3399999);
	b = printf("og: % 10.4f|\n", 3.3399999);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %#.f|\n", 999999.99);
	b = printf("og: %#.f|\n", 999999.99);
		printf("%d)  %d - %d\n\n", i++,  a, b);ft_printf("\nRIGHT ALIGN \n");

	a = ft_printf("my: %-#.f|\n", 999999.99);
	b = printf("og: %-#.f|\n", 999999.99);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %.2f|\n", 9.9999999);
	b = printf("og: %.2f|\n", 9.9999999);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %.f|\n", 9.9999999);
	b = printf("og: %.f|\n", 9.9999999);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %-.4f|\n", 3.3399999);
	b = printf("og: %-.4f|\n", 3.3399999);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %-+010.4f|\n", 3.3399999);
	b = printf("og: %-+010.4f|\n", 3.3399999);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %-+10.4f|\n", 3.3399999);
	b = printf("og: %-+10.4f|\n", 3.3399999);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %-10.4f|\n", -3.3399999);
	b = printf("og: %-10.4f|\n", -3.3399999);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %-010.4f|\n", -3.3399999);
	b = printf("og: %-010.4f|\n", -3.3399999);
	printf("%d)  %d - %d\n\n", i++,  a, b);
	a = ft_printf("my: %-010.4f|\n", 3.3399999);
	b = printf("og: %-010.4f|\n", 3.3399999);
		printf("%d)  %d - %d\n\n", i++,  a, b);
	 
	 a = ft_printf("{%.4f}\n", 1.1);
	b = printf("{%.4f}\n", 1.1);
	printf("%d - %d\n\n", a , b);

	a = ft_printf("% 10.0f|\n", 1.1);
	b = printf("% 10.0f|\n", 1.1);
	printf("%d - %d\n\n", a , b);

	a = ft_printf("%#10.0f|\n", 0.0);
	printf("%#10.0f|\n", 0.0);
	printf("%d - %d\n\n", a , b);

	a = ft_printf("my: %0 20f|\n", -52.9);
	b = printf("og: %0 20f|\n", -52.9);

printf("%d - %d\n\n", a , b);

	a = ft_printf("my: %f|\n", -9.88);
	b = printf("og: %f|\n", -9.88);

printf("%d - %d\n\n", a , b);

	a = ft_printf("my: %.f|\n", 999999.99);
	b = printf("og: %.f|\n", 999999.99);

printf("%d - %d\n\n", a , b);

	a = ft_printf("my: %.f|\n", 89.99);
	b = printf("og: %.f|\n", 89.99);

printf("%d - %d\n\n", a , b);

	a = ft_printf("my: %3.f|\n", 42.123312);
	b = printf("og: %3.f|\n", 42.123312);

printf("%d - %d\n\n", a , b);

	a = ft_printf("my: %f|\n", 1.00);
	b = printf("og: %f|\n", 1.00);

printf("%d - %d\n\n", a , b);

	a = ft_printf("my: %f|\n", 32.23);
	b = printf("og: %f|\n", 32.23);

printf("%d - %d\n\n", a , b);

	a = ft_printf("my: %.5f|\n", 122.358);
	b = printf("og: %.5f|\n", 122.358);

printf("%d - %d\n\n", a , b);


	a = ft_printf("my: %f|\n", 78.221);
	b = printf("og: %f|\n", 78.221);

printf("%d - %d\n\n", a , b);

	a = ft_printf("my: %.0lf|\n", 99999999.1213);
	b = printf("og: %.0lf|\n", 99999999.1213);

printf("%d - %d\n\n", a , b);

	a = ft_printf("my: %f|\n", 0.1223);
	b = printf("og: %f|\n", 0.1223);

printf("%d - %d\n\n", a , b);

	a = ft_printf("my: %f|\n", 10.01010101);
	b = printf("og: %f|\n", 10.01010101);

printf("%d - %d\n\n", a , b);

	a = ft_printf("my: %f|\n", 0.0000);
	b = printf("og: %f|\n", 0.0000);

printf("%d - %d\n\n", a , b);

	a = ft_printf("my: %.2f|\n", 9.9999999);
	b = printf("og: %.2f|\n", 9.9999999);

printf("%d - %d\n\n", a , b);

	a = ft_printf("my: %.f|\n", 9.9999999);
	b = printf("og: %.f|\n", 9.9999999);

	printf("a - %d b - %d\n\n", a, b);

	a = ft_printf("my: %-010.4f|\n", 3.3399999);
	b = printf("og: %-010.4f|\n", 3.3399999);
	printf("a - %d b - %d\n\n", a, b);

	a = printf("{%f}\n", 1.42);
	b = ft_printf("{%f}\n", 1.42);

	printf("%d - %d\n\n", a , b);

	a = printf("{%f}\n", -1.42);
	b = ft_printf("{%f}\n", -1.42);

	printf("%d - %d\n\n", a , b);

	a = printf("{%f}\n", 1444565444646.6465424242242);
	b = ft_printf("{%f}\n", 1444565444646.6465424242242);

	printf("%d - %d\n\n", a , b);

	a = printf("{%f}\n", -1444565444646.6465424242242454654);
	b = ft_printf("{%f}\n", -1444565444646.6465424242242454654);

	printf("%d - %d\n\n", a , b);

	a = printf("{%f}\n", 99.999999999);
	b = ft_printf("{%f}\n", 99.999999999);

	printf("%d - %d\n\n", a , b);
}

int main()
{
	float_checker();
	// int a;
	// int b;
 	// a = printf("%.100f\n", 1.2);
	// b = ft_printf("%.100f\n", 1.2);

	// printf("%d - %d\n\n", a , b);
	return (0);
}