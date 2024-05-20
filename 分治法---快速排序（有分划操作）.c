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
    // 释放动态分配的内存
    free(b);
    free(c);
    free(d);

    return d;
}

int Partition(int a[], int left, int right)
{
    int pivot = a[left]; // 使用第一个元素作为枢纽元素
    int i = left, j = right;
    
    while (i < j)
    {
        // 从右向左找到第一个小于枢纽元素的元素
        while (i < j && a[j] >= pivot)
            j--;
        // 从左向右找到第一个大于枢纽元素的元素
        while (i < j && a[i] <= pivot)
            i++;
        // 如果找到了，则交换它们
        if (i < j)
            Swap(a, i, j);
    }
    // 将枢纽元素放到正确的位置上
    Swap(a, left, j);
    return j; // 返回枢纽元素的位置
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
        QuickSort(a, left, j - 1); // 对枢纽元素左侧的子数组进行排序
        QuickSort(a, j + 1, right); // 对枢纽元素右侧的子数组进行排序
    }
}

int main()
{
    int a[] = {62, 26, 57, 88, 42, 80, 72, 48, 60};
    int left = 0;
    int right = sizeof(a) / sizeof(a[0]) -1;
    int x, r = -1;
    printf("初始顺序为:\n");
    for (int k = 0; k <= right; k++)
    {
        printf("%d ", a[k]);
    }
    printf("\n");
    printf("请输入一个值作为分划元素：");
    scanf("%d", &x);
    // 在数组中查找分划元素的位置
    for (int i = 0; i <= right; i++)
    {
        if (a[i] == x)
        {
            r = i; // 找到分划元素，更新分划元素位置
            break;
        }
    }
    if (r != -1)
    {
        printf("首趟分划结果为：\n");
        int *b = sort(a, x, left, right); // 调用sort函数进行分区
        printf("每一步的排序步骤为：\n");
        QuickSort(b, left, right); // 对分区后的数组进行快速排序
        printf("最终排序结果为：\n");
         for (int k = 0; k <= right; k++)
		{
		    printf("%d ", b[k]);
		}
    }
    return 0;
}
