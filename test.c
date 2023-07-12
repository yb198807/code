#include <stdio.h>
typedef struct stu
{
    char name[20];
    int age;
    char sex[5];
}Stu;
int main()
{
    Stu stu={"chen",18,"nv"};
    Stu* pstu=&stu;
    scanf("%d",&pstu->age);
    printf("%d\n",stu.age);
    printf("%d\n",pstu->age);
    return 0;
}