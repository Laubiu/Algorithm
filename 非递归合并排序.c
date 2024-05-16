#include <stdio.h>

void compare(int a[],int b[],int m,int n,int c[])
{
	int i=0,j=0,k=0;
	while(i<m && j<n)
	{
		if(a[i]<b[j])
		{
			c[k]=a[i];
			k++;
			i++;
		}
		else
		{
			c[k]=b[j];
			k++;
			j++;
		}
	}
	while(i<m)
	{
		c[k]=a[i];
		k++;
		i++;
	}
	while(j<n)
	{
		c[k]=b[j];
		k++;
		j++;
	}
}

int main()
{
	int a[10]={5,15,25,35};
	int m=4;
	int b[10]={10,20,30,32};
	int n=4;
	int c[m+n];
	compare(a,b,m,n,c);
	printf("归并排序后的结果为：\n");
	int i;
	for(i=0;i<m+n;i++)
	{
		printf("%d ",c[i]);
	}
	return 0;
}
