#include <stdio.h>

int sort(int a[], int left, int right)
{
    if (left >= right) 
	{
        return; 
    }
    
    int key = left; 
    int temp, num;
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
    num = a[key];
    a[key] = a[i];
    a[i] = num;
    
    printf("%d %d %d %d\n",i,j,left,right);
    sort(a, left, i - 1);
    sort(a, i + 1, right);
    return 0;
}

int main()
{
    int a[] = {5, 2, 7, 3, 1, 4, 8, 6};
    int left = 0, right = 7;
    printf("��������ǰ�Ľ��Ϊ��\n");
    for (int i = 0; i < right + 1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("\ni��j��left��righÿһ�α仯��ֵ��\n");
    sort(a, left, right);
    printf("\n���������Ľ��Ϊ: \n");
    for (int i = 0; i < right + 1; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
