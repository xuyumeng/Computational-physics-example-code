/*
 * Copyleft by Yumeng Xu
 *
 * Created at March 24,2016
 */

#include <stdio.h>
#include <math.h>

int lorentz(int times, double step);

int main()
{
	int times;
   	double step;

	printf("Please input the data in follow order: \n\r (times step) \n\r");
	scanf("%d %lf",&times,&step);

	lorentz(times,step);
	return 0;
}

double f_x(double x, double y)
{
	return 10 * (y - x);
}

double f_y(double x, double y, double z)
{
	return x * (28 - z) - y;
}

double f_z(double x, double y, double z)
{
	return x * y - 8 / 3 * z;
}

int lorentz(int times, double step)
{
	double x = 5;
	double y = 20;
	double z = -10;
	FILE* fp;

	fp = fopen("data/lorentz.csv","w+");
	for (int i = 0; i < times; i++) {
		x += step * f_x(x,y);
		y += step * f_y(x,y,z);
		z += step * f_z(x,y,z);
		fprintf(fp,"%lf,%lf,%lf\n",x,y,z);
	}

	fclose(fp);
	return 0;
}
