#include <stdio.h>
#include <math.h>

double f(double x);
double dif(double x);
int search(double epsilon);
int dichotomy(double epsilon);
int newton(double epsilon);

int main()
{
	int option;
	double epsilon;

	printf("Please choose the root searching method: \n\r \
			1. Search Method \n\r \
			2. Dichotomy Method \n\r \
			3. Newton Method \n\r");
	scanf("%d",&option);

	printf("Please input the allowable error: \n\r");
	scanf("%lf",&epsilon);

	switch (option) {
		case 1: search(epsilon); break;
		case 2: dichotomy(epsilon); break;
		case 3: newton(epsilon); break;
	}

	return 0;
}

double f(double x)
{
	return (x * x - 5);
}

double dif(double x)
{
	return (2 * x);
}

int search(double epsilon)
{
	double x;
	double step;

	printf("Please input the estimate value of the root: \n\r");
	scanf("%lf",&x);

	printf("Please input the step length:\n\r");
	scanf("%lf",&step);

	while (fabs(f(x)) > epsilon) {
		if (f(x) * f(x + step) < 0) {
			step *= 0.5;
		} else {
			x += step;
		}
	}

	printf("The root is near %lf \n\r",x);
	return 0;
}

int dichotomy(double epsilon)
{
	double min, max;
	double tmp;

	printf("Please input the range where the root located: \n\r");
	scanf("%lf %lf",&min,&max);

	tmp = f((min + max) / 2);

	if (fabs(tmp) > epsilon) {
		while (max - min > epsilon) {
			if (tmp * f(min) > 0) {
				min = (min + max) / 2;
			} else {
				max = (min + max) / 2;
			}
			tmp = f((min + max) / 2);
		}
	}

	printf("The root is near %lf \n\r",(min + max) / 2);
	return 0;
}

int newton(double epsilon)
{
	double x;

	printf("Please input the estimate value of the root: \n\r");
	scanf("%lf",&x);

	while (fabs(f(x)) > epsilon) {
		x = x - f(x) / dif(x);
	}

	printf("The root is near %lf \n\r",x);

	return 0;
}
