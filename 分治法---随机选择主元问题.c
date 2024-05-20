#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ���������һ�η����������ط������������Ԫ������
int *sort1(int a[], int x, int left, int right, int *pivotIndex)
{
    int *b = (int *)malloc((right - left + 1) * sizeof(int));
    int j = 0, k = right - left;

    for (int i = left; i <= right; i++)
    {
        if (a[i] < x)
        {
            b[j++] = a[i];
        }
        else if (a[i] > x)
        {
            b[k--] = a[i];
        }
    }
    b[j] = x;
    *pivotIndex = j;

    // ����ϲ��������, С/�����󣬴�����
    printf("���ֽ��Ϊ��\n");
    for (int i = 0; i <= right - left; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");

    return b;
}

// ��������ĵݹ麯��
void sort2(int a[], int left, int right)
{
    if (left >= right)
        return;

    // ���ѡ��һ��λ����Ϊ��Ԫ
    srand(time(NULL));
    int pivotIndex = left + rand() % (right - left + 1);
    int pivot = a[pivotIndex];
    printf("������ɵ���ԪΪ:%d\n",pivot);
    // ����sort1�������з���
    int n;
    int *sortedArray = sort1(a, pivot, left, right, &n);

    // ������������鸴�ƻ�ԭ����
    for (int i = left; i <= right; i++)
    {
        a[i] = sortedArray[i - left];
    }

    // ��������������еݹ�����
    sort2(a, left, left + n - 1); // ������������������
    sort2(a, left + n + 1, right); // ���Ҳ��������������

    // �ͷŶ�̬������ڴ�
    free(sortedArray);
}

int main()
{
    int a[] = {62, 26, 57, 88, 42, 80, 72, 48, 60};
    int left = 0;
    int right = sizeof(a) / sizeof(a[0]) - 1;

    printf("�������飺\n");
    for (int i = 0; i <= right; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    // ����sort2������������
    sort2(a, left, right);

    printf("������Ϊ��\n");
    for (int i = 0; i <= right; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
