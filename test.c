#include <stdio.h>

int search(int a[],int n)
{
	int i;
	int max=a[0],min=a[0];
	for(i=0;i<n;i++)
	{
		if(max<a[i])
		max=a[i];
		if(min>a[i])
		min=a[i];
	}
	printf("%d %d",max,min);
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int j;
	for(j=0;j<n;j++)
	{
		scanf("%d",&a[j]);
	}
	search(a,n);
	return 0;
}
