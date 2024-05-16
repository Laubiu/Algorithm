#include <stdio.h>

int a[100][100];

void table(int k,int d)
{
	if(k==d)
	    return;
	int i, j;
	for (i = 0; i < d; i++)
	{
		for (j = 0; j < d; j++)
		{
			a[i + d][j + d] = a[i][j];
			a[i][j + d] = a[i][j] + d;
			a[i + d][j] = a[i][j] + d;
		}
	}
	table(k, d*2);
}

int main()
{
	int n;
	printf("一共有多少同学:");
	scanf("%d",&n);
	if (n == 1)
		a[0][0] = 0;
	else
		a[0][0] = 1;
	table(n,1);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
