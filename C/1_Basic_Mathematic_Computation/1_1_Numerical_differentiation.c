/*
 * Copyleft by Yumeng Xu
 * Created at March 7,2016
 */

#include<stdio.h>
#include<math.h>

double f(double x);
int three_point(double step, double x);
int forward_difference(double step, double x);
int backword_difference(double step, double x);
int five_point(double step, double x);
int second_order(double step, double x);

int main()
{
	double step;
	double x;
	int method;
	printf("Please choose the differentiation method:\n\r \
			1. \"3-point\" formula \n\r \
			2. forward difference formula \n\r \
			3. backword difference formula \n\r \
			4. \"5-point\" formula \n\r \
			5. second order difference \n\r \
			0. show all results above \n\r \
			\n\r");
	scanf("%d",&method);

	printf("Please input the step of differentiation:\n\r");
	scanf("%lf",&step);

	printf("Input the differentiation point (x):\n\r");
	scanf("%lf",&x);

	switch (method) {
		case 1: three_point(step,x); break;
		case 2: forward_difference(step,x); break;
		case 3: backword_difference(step,x); break;
		case 4: five_point(step,x); break;
		case 5: second_order(step,x); break;
		case 0: three_point(step,x);
				forward_difference(step,x);
				backword_difference(step,x);
				five_point(step,x);
				second_order(step,x);
				break;
	}

	return 0;
}

double f(double x)
{
	return sin(x);
}

int three_point(double step, double x)
{
	double result = 0;
	result = (f(x + step) - f(x - step)) / (2.0 * step);
	printf("The \"3-point\" formula result is %.13lf \n\r",result);
	return 0;
}

int forward_difference(double step, double x)
{
	double result = 0;
	result = (f(x + step) - f(x)) / step;
	printf("The forward difference formula result is %.13lf \n\r",result);
	return 0;
}

int backword_difference(double step, double x)
{
	double result = 0;
	result = (f(x) - f(x - step)) / step;
	printf("The backword_differenced formula result is %.13lf \n\r",result);
	return 0;
}

int five_point(double step, double x)
{
	double result = 0;
	result = (f(x - 2 * step) - 8 * f(x - step) + 8 * f(x + step) - f(x - 2 * step) ) / (12 * step);
	printf("The \"5-point\" formula results is %.13lf \n\r",result);
	return 0;
}

int second_order(double step, double x)
{
	double result = 0;
	result = (f(x + step) - 2 * f(x) + f(x - step)) / (x * x);
	printf("The second order difference results is %.13lf \n\r",result);
	return 0;
}
