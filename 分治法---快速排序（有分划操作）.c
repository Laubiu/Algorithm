#include <stdio.h>
#include <stdlib.h>

void Swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int *sort(int a[], int x, int left, int right)
{
    int *b = (int *)malloc((right - left + 1) * sizeof(int));
    int *c = (int *)malloc((right - left + 1) * sizeof(int));
    int *d = (int *)malloc((right - left + 1) * sizeof(int));
    int j = 0, k = 0;

    for (int i = left; i <= right; i++)
    {
        if (a[i] <= x)
        {
            b[j] = a[i];
            j++;
        }
        if (a[i] > x)
        {
            c[k] = a[i];
            k++;
        }
    }

    for(int i = 0; i < j; i++)
    {
        d[i] = b[i];
    }
    for(int i = 0; i < k; i++)
    {
        d[j+i]=c[i];
    }
    for(int i = left; i <= right; i++)
    {
		printf("%d ",d[i]);
	}
	printf("\n");
    // �ͷŶ�̬������ڴ�
    free(b);
    free(c);
    free(d);

    return d;
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
    return j; // ������ŦԪ�ص�λ��
}

void QuickSort(int a[], int left, int right)
{
    if (left < right)
    {
        int j = Partition(a, left, right);
        for(int k=left;k<right+1;k++)
        {
			printf("%d ",a[k]);
		}
		printf("\n");
        QuickSort(a, left, j - 1); // ����ŦԪ�������������������
        QuickSort(a, j + 1, right); // ����ŦԪ���Ҳ���������������
    }
}

int main()
{
    int a[] = {62, 26, 57, 88, 42, 80, 72, 48, 60};
    int left = 0;
    int right = sizeof(a) / sizeof(a[0]) -1;
    int x, r = -1;
    printf("��ʼ˳��Ϊ:\n");
    for (int k = 0; k <= right; k++)
    {
        printf("%d ", a[k]);
    }
    printf("\n");
    printf("������һ��ֵ��Ϊ�ֻ�Ԫ�أ�");
    scanf("%d", &x);
    // �������в��ҷֻ�Ԫ�ص�λ��
    for (int i = 0; i <= right; i++)
    {
        if (a[i] == x)
        {
            r = i; // �ҵ��ֻ�Ԫ�أ����·ֻ�Ԫ��λ��
            break;
        }
    }
    if (r != -1)
    {
        printf("���˷ֻ����Ϊ��\n");
        int *b = sort(a, x, left, right); // ����sort�������з���
        printf("ÿһ����������Ϊ��\n");
        QuickSort(b, left, right); // �Է������������п�������
        printf("����������Ϊ��\n");
         for (int k = 0; k <= right; k++)
		{
		    printf("%d ", b[k]);
		}
    }
    return 0;
}
