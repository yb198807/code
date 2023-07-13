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
int main()
{
    int arr[]={1,2,3,4,5};
    int* p=arr;
    int a;
    for(a=0;a<5;a++)
    {
        printf("%d\n",*(p+a));
    }
    return 0;
}