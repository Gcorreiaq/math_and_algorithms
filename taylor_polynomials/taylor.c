#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int factorial(int x)
{
	int result = x;
	for (;x > 2;x--)
		result *= x-1;
	return result;
}

double taylor(int n, double x)
{
	double result = 0;
	result = (pow(-1,n) * pow(x, (2 * n) + 1)) / (factorial((2 * n) + 1));
	return result;
}

int main (int argc, char *argv[])
{
	int n = atoi(argv[1]);
	double x = atof(argv[2]);
	double result = taylor(0,x);
	for (int i = 1;i < n + 1;i++)
	{
		result += taylor(i,x);
	}
	printf("taylor:%f sin:%f\n", result, sin(x));
	return 0;
}
