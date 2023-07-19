#include <stdio.h>
#include <string.h>
void cpy(void* b,const void* a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		*(char*)b++=*(char*)a++;
	}
}
int main()
{
	int a[]={1,2,3,4,5};
	int b[5]={0};
	cpy(b,a,sizeof(a));
	return 0;
}