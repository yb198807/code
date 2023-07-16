#include <stdio.h>
int fun(int a, int b)
{
	int sum = 1;
	while (b--)
	{
		sum *= a;
	}
	return sum;
}
int main()
{
	int a = 2, b = 4;
	int sum = fun(a, b);
	printf("%d\n", sum);
	return 0;
}