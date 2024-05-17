#include <stdio.h>

void Swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
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
    printf("排序结果为：\n");
    for (int k = left; k < right + 1; k++)
	{
        printf("%d ", a[k]);
    }
    printf("\n");
    return j; // 返回枢纽元素的位置
}

void QuickSort(int a[], int left, int right)
{
    if (left < right)
    {
        int pivotIndex = Partition(a, left, right);
        QuickSort(a, left, pivotIndex - 1); // 对枢纽元素左侧的子数组进行排序
        QuickSort(a, pivotIndex + 1, right); // 对枢纽元素右侧的子数组进行排序
    }
}

int main()
{
    int a[] = {72, 26, 57, 88, 42, 80, 72, 48, 60};
    int len = sizeof(a) / sizeof(a[0]);
    printf("初始顺序为:\n");
	for (int k = 0; k < len; k++)
	{
	    printf("%d ", a[k]);
	}
	printf("\n");
    QuickSort(a, 0, len - 1);
    printf("最终排序结果为:\n");
    for (int k = 0; k < len; k++)
    {
        printf("%d ", a[k]);
    }
    
    return 0;
}
