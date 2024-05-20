#include <stdio.h>

void sort(int a[], int left, int right)
{
    if (left >= right) 
	{
        return; 
    }
    
    int key = left; 
    int temp;
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && a[key] <= a[j])
        {
            j--;
        }
        while (i < j && a[key] >= a[i])
        {
            i++;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[key];
    a[key] = a[i];
    a[i] = temp;
    
    for (int k = left; k <= right; k++)
    {
        printf("%d ", a[k]);
    }
    printf("\n");
    
    sort(a, left, i - 1);
    sort(a, i + 1, right);
}

int main()
{
    int a[] = {5, 2, 7, 3, 1, 4, 8, 6};
    int left = 0, right = 7;
    printf("�ݹ��������ǰ�Ľ��Ϊ��\n");
    for (int i = 0; i < right + 1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("\n�����������Ϊ��\n");
    sort(a, left, right);
    printf("\n�ݹ���������Ľ��Ϊ: \n");
    for (int i = 0; i < right + 1; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
