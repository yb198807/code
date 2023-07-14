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
void print(int a)
{
    printf("aaa\n");
}
int main()
{
    void(*pa)(int)=print;
    pa(5);
    return 0;
}
