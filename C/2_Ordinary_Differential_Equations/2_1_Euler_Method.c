/*
 * Copyleft by Yumeng Xu
 * Created at March 24,2016
 */

#include <stdio.h>
#include <math.h>

double f(double x, double y);

double eular(double x_0, double y_0, double x_n, double step);
double taylar(double x_0, double y_0, double x_n, double step);
double adams_bashforth(double x_0, double y_0, double x_n, double step);

int print_eular(double x_0, double y_0, double x_n, double step);
int print_taylar(double x_0, double y_0, double x_n, double step);
int print_adams_bashforth(double x_0, double y_0, double x_n, double step);

int main()
{
	int method;
	double x_0;
	double y_0;
	double x_n;
   	double step;

	printf("Please choose the solve method: \n\r \
			1. Eular Method \n\r \
			2. Taylar Method \n\r \
			3. Adams Bashforth \n\r");
	scanf("%d",&method);

	printf("Please input the data in follow order: \n\r (x_0 y_0 x_n step) \n\r");
	scanf("%lf %lf %lf %lf",&x_0,&y_0,&x_n,&step);

	switch (method) {
		case 1: print_eular(x_0,y_0,x_n,step);break;
		case 2: print_taylar(x_0,y_0,x_n,step);break;
		case 3: print_adams_bashforth(x_0,y_0,x_n,step);break;
	}
	return 0;
}

double f(double x, double y)
{
	return - x * y;
}

double df_dy(double x)
{
	return - x;
}

double df_dx(double y)
{
	return - y;
}

int print_eular(double x_0, double y_0, double x_n, double step)
{
	double res = eular(x_0,y_0,x_n,step);
	printf("The result of eular method is : %lf \n\r",res);
	return 0;
}

int print_taylar(double x_0, double y_0, double x_n, double step)
{
	double res = taylar(x_0,y_0,x_n,step);
	printf("The result of taylar method is : %lf \n\r",res);
	return 0;
}

int print_adams_bashforth(double x_0, double y_0, double x_n, double step)
{
	double res = adams_bashforth(x_0,y_0,x_n,step);
	printf("The result of dams bashforth method is : %lf \n\r",res);
	return 0;
}

double eular(double x_0, double y_0, double x_n, double step)
{
	double y = y_0;
	double x = x_0;

	for (int i = 0; i * step < (x_n - x_0); i++) {
		x += step;
		y += step * f(x,y);
	}

	return y;
}

double taylar(double x_0, double y_0, double x_n, double step)
{
	double y = y_0;
	double x = x_0;

	for (int i = 0; i * step < (x_n - x_0); i++) {
		x += step;
		y += step * f(x,y) + 0.5 * step * step * (df_dx(y) + f(x,y) * df_dy(x));
	}
	return y;
}

double adams_bashforth(double x_0, double y_0, double x_n, double step)
{
	double y_before = y_0;
	double x_before = x_0;
	double x = x_0;
	double y_t;

	double y = taylar(x_0,y_0,step,step);

	for (int i = 0; i * step < (x_n - x_0); i++) {
		x += step; // x_n
		y_t = y; // store y_n
		y += step * (3 / 2 * f(x,y) - 1 / 2 * f(x_before,y_before));  // get y_(n+1)
		x_before = x; // transfer x_n to x_before
		y_before = y_t;
	}
	return y;
}
