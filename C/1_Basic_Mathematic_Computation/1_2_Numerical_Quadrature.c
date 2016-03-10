#include <stdio.h>
#include <math.h>

int trapezoidal_rule(int n, double min, double max);
int simpsons_rule(int n, double min, double max);
double f(double x);

int main()
{
	int option;
	int n;
	double min;
	double max;

	printf("Please choose the integral method: \n\r \
			1. Trapezoidal Rule \n\r \
			2. Simpson's Rule \n\r \
			0. Use all method above \n\r \
			");
	scanf("%d",&option);

	printf("Seperate the integral area into N part(Please input the N):\n\r");
	scanf("%d",&n);

	printf("Please input the lower limit and the upper limit of the integral area\n\r");
	scanf("%lf %lf",&min,&max);

	switch (option) {
		case 1: trapezoidal_rule(n,min,max); break;
		case 2: simpsons_rule(n,min,max); break;
		case 0: trapezoidal_rule(n,min,max);
				simpsons_rule(n,min,max);
				break;
	}
	return 0;
}

double f(double x)
{
	return exp(x);
}

int trapezoidal_rule(int n, double min, double max)
{
	double result;
	double step;

	step = (max - min) / n;

	result = 0.5 * f(min);

	for (double x = min + step;x <= max - step;x += step) {
		result += f(x);
	}

	result += 0.5 * f(max);

	printf("The result of Trapezoidal Rule is %.13lf \n\r",result * step);

	return 0;
}

int simpsons_rule(int n, double min, double max)
{
	double result;
	double step;
	double even_part = 0;
	double odd_part = 0;

	if (n % 2 == 0) {
		step = (max - min) / n;
	} else {
		printf("N must be even in Simpson's Rule! \n\r!");
		return 0;
	}

	for (int i = 1;i < n;i++) {
		if (i % 2 == 0) {
			even_part += f(min + i * step);
		} else {
			odd_part += f(min + i * step);
		}
	}

	result = 2 / 3 * even_part + 4 / 3 * odd_part + 1 / 3 * (f(min) + f(max));

	printf("The result of Simpson's Rule is %.13lf \n\r",result * step);

	return 0;
}
