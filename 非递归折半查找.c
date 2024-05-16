#include <stdio.h>
#include <string.h>
int main()
{
	int a[9]={1,2,3,5,7,9,10,15,16};
	int left=0,right=8;
	int m=(left+right)/2;
	int k=15;
	int count=0;
	while(left<=right)
	{
		if(k<a[m])
		{
			right=m;
			m=(left+right)/2;
			count++;
		}
		else if(k>a[m])
		{
			left=m;
			m=(left+right)/2;
			count++;
		}
		else
		{
		    k=a[m];
		    count++;
		    break;
		}
	}
	printf("在第%d位查找到了该数字\n",m+1);
	printf("查找了%d次",count);
	return 0;
}
