#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 将数组进行一次分区，并返回分区后数组和主元的索引
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

    // 输出合并后的数组, 小/等在左，大在右
    printf("划分结果为：\n");
    for (int i = 0; i <= right - left; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");

    return b;
}

// 快速排序的递归函数
void sort2(int a[], int left, int right)
{
    if (left >= right)
        return;

    // 随机选择一个位置作为主元
    srand(time(NULL));
    int pivotIndex = left + rand() % (right - left + 1);
    int pivot = a[pivotIndex];
    printf("随机生成的主元为:%d\n",pivot);
    // 调用sort1函数进行分区
    int n;
    int *sortedArray = sort1(a, pivot, left, right, &n);

    // 将分区后的数组复制回原数组
    for (int i = left; i <= right; i++)
    {
        a[i] = sortedArray[i - left];
    }

    // 对左右子数组进行递归排序
    sort2(a, left, left + n - 1); // 对左侧子数组进行排序
    sort2(a, left + n + 1, right); // 对右侧子数组进行排序

    // 释放动态分配的内存
    free(sortedArray);
}

int main()
{
    int a[] = {62, 26, 57, 88, 42, 80, 72, 48, 60};
    int left = 0;
    int right = sizeof(a) / sizeof(a[0]) - 1;

    printf("输入数组：\n");
    for (int i = 0; i <= right; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    // 调用sort2函数进行排序
    sort2(a, left, right);

    printf("排序结果为：\n");
    for (int i = 0; i <= right; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
