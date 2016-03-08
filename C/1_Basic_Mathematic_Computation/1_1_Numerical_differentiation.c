/*
 * Copyleft by Yumeng Xu
 * Created at March 7,2016
 */

#include<stdio.h>
#include<math.h>

double f(double x);
int three_point(double step);
int forward_difference(double step);
int backword_difference(double step);
int five_point(double step);

int main()
{
	double step;
	int method;
	printf("Please choose the differentiation method:\n\r \
			1. \"3-point\" formula \n\r \
			2. forward difference formula \n\r \
			3. backword difference formula \n\r \
			4. \"5-point\" formula \n\r \
			\n\r");
	scanf("%d",&method);

	printf("Please input the step of differentiation:\n\r");
	scanf("%lf",&step);

	switch (method) {
		case 1: three_point(step); break;
		case 2: forward_difference(step); break;
		case 3: backword_difference(step); break;
		case 4: five_point(step); break;
	}

	return 0;
}

double f(double x)
{
	return sin(x);
}

int three_point(double step)
{
	double result = 0;
	result = (f(0 + step) - f(0 - step)) / (2.0 * step);
	printf("The \"3-point\" formula result is %.13lf \n\r",result);
	return 0;
}

int forward_difference(double step)
{
	double result = 0;
	result = (f(0 + step) - f(0)) / step;
	printf("The forward difference formula result is %.13lf \n\r",result);
	return 0;
}

int backword_difference(double step)
{
	double result = 0;
	result = (f(0) - f(0 - step)) / step;
	printf("The backword_differenced formula result is %.13lf \n\r",result);
	return 0;
}

int five_point(double step)
{
	double result = 0;
	result = (f(0 - 2 * step) - 8 * f(0 - step) + 8 * f(0 + step) - f(0 - 2 * step) ) / (12 * step);
	printf("The \"5-point\" formula results is %.13lf /n/r",result);
	return 0;
}
