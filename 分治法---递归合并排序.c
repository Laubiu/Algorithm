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
        int mid = (right + left) / 2; // �����м�Ԫ�ص�λ��
        mergeSort(arr, left, mid); //�����󲿷�
        mergeSort(arr, mid + 1, right); //�����Ҳ���
        merge(arr, left, mid, right); //�ϲ����������������
	}
}

int main()
{
	int arr[] = {64, 25, 12, 22, 11, 17, 34};
	int n = sizeof(arr)/sizeof(arr[0]);
	// ���ù鲢������
	mergeSort(arr, 0, n - 1);
	// �������������
	printf("����������: \n");
	for (int i = 0; i < n; i++) 
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
