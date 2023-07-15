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
    int s,n,i;
    scanf("%d%d",&s,&n);
    int sum=0;
    int ret=0;
    for(i=1;i<=s;i++)
    {
        ret=ret*10+n;
        sum+=ret;
    }
    printf("%d\n",sum);
    return 0;
}
