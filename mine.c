#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define row 9
#define col 9
#define easy 10
#define Row row + 2
#define Col col + 2
void createmine(int mine[Row][Col],int a,int b)
{
    int n = easy;
    while (n)
    {
        int x, y;
        x = rand() % 9 + 1;
        y = rand() % 9 + 1;
        if (mine[x][y] == 0&&(a!=x||b!=y))
        {
            mine[x][y] = 1;
            n--;
        }
    }
}
void printshow(char show[Row][Col])
{
    int i, j;
    for (i = 0; i < row + 1; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 1; i < Row - 1; i++)
    {
        printf("%d ", i);
        for (j = 1; j < Col - 1; j++)
        {
            printf("%c ", show[i][j]);
        }
        printf("\n");
    }
}
void printmine(int mine[Row][Col])
{
    int i, j;
    for (i = 0; i < row + 1; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 1; i < Row - 1; i++)
    {
        printf("%d ", i);
        for (j = 1; j < Col - 1; j++)
        {
            printf("%d ", mine[i][j]);
        }
        printf("\n");
    }
}
void panduan(int mine[Row][Col], char show[Row][Col], int x, int y)
{
    int i, j, a = 0;
    for (i = x - 1; i <= x + 1; i++)
    {
        for (j = y - 1; j <= y + 1; j++)
        {
            if (mine[i][j] == 1)
                a++;
        }
    }
    show[x][y] = a + 48;
    if (a == 0)
    {
        show[x][y] = ' ';
        if (x > 0 && x <= row && y > 0 && y <= col)
        {
            for (i = x - 1; i <= x + 1; i++)
            {
                for (j = y - 1; j <= y + 1; j++)
                {
                    if (show[i][j] == '*')
                        panduan(mine, show, i, j);
                }
            }
        }
    }
}
int win(char show[Row][Col])
{
    int i, j, n = 0;
    for (i = 1; i < row + 1; i++)
    {
        for (j = 1; j < col + 1; j++)
        {
            if (show[i][j] == '*')
                n++;
        }
    }
    if (n == easy)
        return 1;
    else
        return 0;
}
int main()
{
    int mine[Row][Col] = {0};
    char show[Row][Col] = {0};
    srand((unsigned int)time(NULL));
    int i, j, input;
    while (1)
    {
        printf("*************************\n*****1.play   0.exit*****\n*************************\n请选择：");
        for (i = 1; i < Row - 1; i++)
        {
            for (j = 1; j < Col - 1; j++)
            {
                mine[i][j] = 0;
                show[i][j] = '*';
            }
        }
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printshow(show);
            int x, y, a=1;
            while (1)
            {
                printf("输入排雷坐标：");
                scanf("%d%d", &x, &y);
                while(a)
                {
                    createmine(mine,x,y);
                    a--;
                }
                if (x > 0 && x <= row && y > 0 && y <= col)
                {
                    if (show[x][y] == '*')
                    {
                        if (mine[x][y] == 0)
                        {
                            panduan(mine, show, x, y);
                            int n = win(show);
                            if (n == 1)
                            {
                                printmine(mine);
                                printf("你赢了！\n");
                                break;
                            }
                            else
                            printshow(show);
                        }
                        else
                        {
                            printmine(mine);
                            printf("踩雷了！\n");
                            break;
                        }
                    }
                    else
                        printf("坐标有误！\n");
                }
                else
                    printf("坐标有误，重新输入：");
            }
            continue;
        case 0:
            printf("游戏结束\n");
            break;
        default:
            printf("输入错误，重新输入：");
            continue;
        }
        break;
    }
    return 0;
}