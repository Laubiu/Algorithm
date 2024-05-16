//非递归合并排序
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

---------------------------------------------------------
//递归合并排序（归并）
#include <stdio.h>

void merge(int arr[],int left,int mid,int right)
{
	int m=mid-left+1;
	int n=right-mid;
	int b[m],c[n];
	int i,j,k=left;
	for(i=0;i<m;i++)
	{
		b[i]=arr[left+i];
	}
	for(j=0;j<n;j++)
	{
		c[j]=arr[mid+j+1];
	}
	i=0,j=0;
	while(i<m && j<n)
	{
		if (b[i] < c[j]) 
		{
		    arr[k] = b[i];
		    i++;
		    k++;
		}
		else 
		{
		    arr[k] = c[j];
		    j++;
		    k++;
		}
	}
	while (i < m) 
	{
	    arr[k] = b[i];
	    i++;
	    k++;
	}
	while (j < n) 
	{
	    arr[k] = c[j];
	    j++;
	    k++;
	}
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
	{
        int mid = (right + left) / 2; // 计算中间元素的位置
        mergeSort(arr, left, mid); //排序左部分
        mergeSort(arr, mid + 1, right); //排序右部分
        merge(arr, left, mid, right); //合并两个有序的子数组
	}
}

int main()
{
	int arr[] = {64, 25, 12, 22, 11, 17, 34};
	int n = sizeof(arr)/sizeof(arr[0]);
	// 调用归并排序函数
	mergeSort(arr, 0, n - 1);
	// 输出排序后的数组
	printf("排序后的数组: \n");
	for (int i = 0; i < n; i++) 
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
