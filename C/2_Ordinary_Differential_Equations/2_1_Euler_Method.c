/*
 * Copyleft by Yumeng Xu
 * Created at March 24,2016
 */

#include <stdio.h>
#include <math.h>

double f(double x, double y);

double eular(double x_0, double y_0, double x_n, double step);
int print_eular(double x_0, double y_0, double x_n, double step);

int main()
{
	int method;
	double x_0;
	double y_0;
	double x_n;
   	double step;

	printf("Please choose the solve method: \n\r \
			1. Eular Method \n\r");
	scanf("%d",&method);

	printf("Please input the data in follow order: \n\r (x_0 y_0 x_n step) \n\r");
	scanf("%lf %lf %lf %lf",&x_0,&y_0,&x_n,&step);

	switch (method) {
		case 1: print_eular(x_0,y_0,x_n,step);break;
	}
	return 0;
}

double f(double x, double y)
{
	return - x * y;
}

int print_eular(double x_0, double y_0, double x_n, double step)
{
	double res = eular(x_0,y_0,x_n,step);
	printf("The result of eular method is : %lf \n\r",res);
	return 0;
}

double eular(double x_0, double y_0, double x_n, double step)
{
	double y = y_0;
	double x = x_0;

	for (int i = 0; i * step < (x_n - x_0); i++) {
		x += step;
		y = y + step * f(x,y);
	}

	return y;
}
