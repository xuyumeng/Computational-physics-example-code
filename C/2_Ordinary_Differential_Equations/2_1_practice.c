/*
 * Copyleft by Yumeng Xu
 *
 * Created at March 24,2016
 */

#include <stdio.h>
#include <math.h>

int euler(double step);
int runge_kutta(double step);
int adams(double step);
double f_x(double x);
double f_y(double y);

int main()
{
   	double step = 0.1;


	euler(step);
	runge_kutta(step);
	adams(step);
	return 0;
}

inline double f_x(double y)
{
	return -0.73 * y;
}

inline double f_y(double x)
{
	return 0.34 * x;
}

int euler(double step)
{
	double x = 1;
	double y = 1;
	double time = 2000;
	FILE* fp;

	fp = fopen("data/p_euler.csv","w+");
	for (double i = 0; i < time; i += step) {
		x += step * f_x(y);
		y += step * f_y(x);
		fprintf(fp,"%lf,%lf\n",x,y);
	}

	fclose(fp);
	return 0;
}

int runge_kutta(double step)
{
	double x = 1;
	double y = 1;
	double time = 2000;
	double k_1,k_2,k_3,k_4;
	double l_1,l_2,l_3,l_4;
	FILE* fp;

	fp = fopen("data/p_rk.csv","w+");
	for (double i = 0;i < time; i += step) {
		k_1 = f_x(y);
		l_1 = f_y(x);
		k_2 = f_x(y + step/2 * l_1);
		l_2 = f_y(x + step/2 * k_1);
		k_3 = f_x(y + step/2 * l_2);
		l_3 = f_y(x + step/2 * k_2);
		k_4 = f_x(y + step * l_3);
		l_4 = f_y(x + step * k_3);

		fprintf(fp,"%lf,%lf\n",x,y);

		x += step / 6 * (k_1 + 2 * k_2 + 2 * k_3 + k_4);
		y += step / 6 * (l_1 + 2 * l_2 + 2 * l_3 + l_4);

	}
	fclose(fp);
	return 0;
}

int adams(double step)
{
	double x = 1;
	double y = 1;
	double x_2, x_3;
	double y_2, y_3;
	double time = 2000;
	FILE* fp;

	x_2 = x + step * f_x(y);
	y_2 = x + step * f_y(x);

	fp = fopen("data/p_adams.csv","w+");
	for (double i = 0; i < time; i += step) {
		x_3 = x_2 + step / 2 * (3 * f_x(y_2) - f_x(y));
		x_3 = x_2 + step / 2 * (f_x(y_2) + x_3);
		y_3 = y_2 + step / 2 * (3 * f_y(x_2) - f_y(x));
		y_3 = y_2 + step / 2 * (f_y(x_2) + y_3);


		fprintf(fp,"%lf,%lf\n",x,y);
		x = x_2; y = y_2;
		x_2 = x_3; y_2 = y_3;
	}

	return 0;
}
