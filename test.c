#include <stdio.h>
// int *twoSum(int *nums, int numsSize, int target)
// {
//     int i, j;
//     for (i = 0; i < j; i++)
//     {
//         for (j = i + 1; j < numsSize; j++)
//         {
//             if (nums[i] + nums[j] == target)
//             {
//                 int arr[2] = {i, j};
//                 return arr;
//             }
//         }
//     }
// }
#include <math.h>
int reverse2(int x)
{
	long n = 0;
	while (x != 0)
	{
		n = n * 10 + x % 10;
		x = x / 10;
	}
	return (int)n == n ? (int)n : 0;
}
int reverse(int x)
{
	long sum = 0;
	if (x >= 0)
	{
		int count = 1;
		int tmp = x;
		while (tmp / 10)
		{
			count++;
			tmp /= 10;
		}
		while (count--)
		{
			sum += (x % 10) * pow(10, count);
			x /= 10;
		}
		if ((int)sum == sum)
			return (int)sum;
		else
			return 0;
	}
	else
		return (int)(-reverse(-x));
}
int main()
{
	printf("%d\n", reverse2(123));
	// printf("%d\n",reverse(2147483647));
	return 0;
}
