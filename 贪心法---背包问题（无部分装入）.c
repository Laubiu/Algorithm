#include <stdio.h>

struct goods
{
	int num;
    float w;
    float v;
    float ave;
};

void compare(struct goods g[], int n)
{
    printf("单位质量价值从大到小分别为：\n");
    struct goods temp;
    for (int j = 0; j < n; j++)
    {
        g[j].ave = g[j].v / g[j].w;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (g[j].ave < g[j + 1].ave)
            {
                temp = g[j];
                g[j] = g[j + 1];
                g[j + 1] = temp;
            }
        }
    }
}

int push(struct goods g[],int m,int n)
{
	printf("放入背包的物品有：");
	int p[n];
	float sum=0;
	for(int i=0;i<n;i++)
	{
		if(m-g[i].w>0)
		{
			m=m-g[i].w;
			p[i]=g[i].num;
			sum=sum+g[i].v;
		}
		else
		    break;
		printf("%d  ",p[i]);
	}
	printf("\n不支持部分装的情况下，最大的收益为: %.2f",sum);
	return 0;
}

int main()
{
    struct goods items[7] = {{1, 2, 10}, {2, 3, 5}, {3, 5, 15}, {4, 7, 7}, {5, 1, 6}, {6, 4, 18}, {7, 1, 3}};
    int n = 7;
    compare(items, n);
    for (int i = 0; i < n; i++)
    {
        printf("物品%d的质量及单位质量价值为： %.2f %.2f \n",items[i].num,items[i].w,items[i].ave);
    }
    push(items,15,n);
    return 0;
}
