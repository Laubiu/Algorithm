#include <stdio.h>

void sort(int a[],int left,int right)
{
	int key=0;
	int temp=0,num=0;
	while(left<right)
	{
		while(left<right && a[key]<=a[right])
		{
			right--;
		}
		while(left<right && a[key]>=a[left])
		{
			left++;
		}
		if(left<right)
		{
			temp=a[left];
			a[left]=a[right];
			a[right]=temp;
		}
		else if(left==right)
		{
			num=a[key];
			a[key]=a[right];
			a[right]=num;
		}
		else
		break;
	}
	
}

int main()
{
	int a[]={5,2,7,3,1,4,8,6};
	int left=0,right=7;
	printf("快速排序前的结果为：\n");
	for(int i=0;i<right+1;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	sort(a,left,right);
	printf("快速排序的单趟结果为: \n");
	for(int i=0;i<right+1;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
