#ifndef STDIO
#define STDIO
#include <stdio.h>
#endif

double eular(double (*f)(double x,double y),double x_0, double y_0, double x_n, double step)
{
	double y = y_0;
	double x = x_0;

	for (int i = 0; i * step <= (x_n - x_0); i++) {
		y += step * (*f)(x,y);
		x += step;
	}

	return y;
}

int print_eular(double (*f)(double x,double y),double x_0, double y_0, double x_n, double step)
{
	double res = eular((*f),x_0,y_0,x_n,step);
	printf("The result of eular method is : %lf \n\r",res);
	return 0;
}
