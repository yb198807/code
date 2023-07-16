#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    char arr[50][50] = {0};
    int i = 0;
    for (i = 0; i < 2 * n - 1; i++)
    {
        int j = 0;
        for (j = 0; j < 2 * n - 1; j++)
        {
            arr[i][j] = ' ';
        }
    } // 初始化数组
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = n - i - 1; j < n + i; j++)
        {
            arr[i][j] = '*';
        }
    } // 上半部分*号
    for (i = n; i < 2 * n - 1; i++)
    {
        int j = 0;
        for (j = i - n + 1; j < 3 * n - i - 2; j++)
        {
            arr[i][j] = '*';
        }
    } // 下半部分*号
    for (i = 0; i < 2 * n - 1; i++)
    {
        int j = 0;
        for (j = 0; j < 2 * n - 1; j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    } // 打印数组
    return 0;
}