#include <stdio.h>

void Swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int Partition(int a[], int left, int right)
{
    int pivot = a[left]; // ʹ�õ�һ��Ԫ����Ϊ��ŦԪ��
    int i = left, j = right;
    
    while (i < j)
    {
        // ���������ҵ���һ��С����ŦԪ�ص�Ԫ��
        while (i < j && a[j] >= pivot)
            j--;
        // ���������ҵ���һ��������ŦԪ�ص�Ԫ��
        while (i < j && a[i] <= pivot)
            i++;
        // ����ҵ��ˣ��򽻻�����
        if (i < j)
            Swap(a, i, j);
    }
    // ����ŦԪ�طŵ���ȷ��λ����
    Swap(a, left, j);
    printf("������Ϊ��\n");
    for (int k = left; k < right + 1; k++)
	{
        printf("%d ", a[k]);
    }
    printf("\n");
    return j; // ������ŦԪ�ص�λ��
}

void QuickSort(int a[], int left, int right)
{
    if (left < right)
    {
        int pivotIndex = Partition(a, left, right);
        QuickSort(a, left, pivotIndex - 1); // ����ŦԪ�������������������
        QuickSort(a, pivotIndex + 1, right); // ����ŦԪ���Ҳ���������������
    }
}

int main()
{
    int a[] = {72, 26, 57, 88, 42, 80, 72, 48, 60};
    int len = sizeof(a) / sizeof(a[0]);
    printf("��ʼ˳��Ϊ:\n");
	for (int k = 0; k < len; k++)
	{
	    printf("%d ", a[k]);
	}
	printf("\n");
    QuickSort(a, 0, len - 1);
    printf("����������Ϊ:\n");
    for (int k = 0; k < len; k++)
    {
        printf("%d ", a[k]);
    }
    
    return 0;
}
