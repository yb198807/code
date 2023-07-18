#include <stdio.h>
#include <string.h>
int find(int(*arr)[4],int n)
{
	int i;
	for(i=0;i<3;i++)
	{
		if(arr[i][3]>n)
		break;
	}
	int j;
	for(j=3;j>=0;j--)
	{
		if(arr[i][j]==n)
		return 1;
	}
	return 0;
}
int main()
{
	int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	int n=7;
	int a=find(arr,n);
	printf("%s\n", a==1?"Yes":"No");
	return 0;
}