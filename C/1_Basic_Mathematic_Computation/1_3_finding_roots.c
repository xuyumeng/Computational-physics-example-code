#include <stdio.h>
#include <math.h>

double f(double x);
int search(double epsilon);
int dichotomy(double epsilon);

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
	}

	return 0;
}

double f(double x)
{
	return (x * x - 5);
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
	double x;
	double min, max;
	  double tmp;

	printf("Please input the range where the root located: \n\r");
	scanf("%lf %lf",&min,&max);

	tmp = f((min + max) / 2);

	if (tmp > epsilon) {
		while (max - min < epsilon) {
			if (tmp * f(min) > 0) {
				min = (min + max) / 2;
			} else {
				max = (min + max) / 2;
			}
			tmp = f((min + max) / 2);
		}
	}

	printf("The root is near %lf",tmp);
	return 0;
}
