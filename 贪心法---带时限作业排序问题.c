#include <stdio.h>

struct works
{
    int no;
    int profile;
    int time;
};

void sort(struct works a[], int n)
{
    int num = 0,value=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            
            if(a[j].profile<a[j+1].profile)
            {
				value = a[j].profile;
				a[j].profile = a[j + 1].profile;
				a[j + 1].profile = value;
				
				num = a[j].no;
				a[j].no = a[j + 1].no;
				a[j + 1].no = num;
			}
        }
    }
}

int push(struct works a[],int n)
{
	printf("所选择的作业有：");
	int p[n],count=0,sum=0;
	p[0]=a[0].no;
	int m=a[0].time;
	int nn=1;
	int i=1;
	while(m>0)
	{
		if(m>=a[i].time)
		{
			nn++;
			p[i]=a[i].no;
			m=m-nn;
			count++;
			sum=sum+a[i].profile;
		}
		else if(a[i].time>m)
		{
			nn++;
			p[i]=a[i].no;
			m=a[i].time-nn;
			count++;
			sum=sum+a[i].profile;
		}
		else
		    break;
		i++;
	}
	
	for(int i=0;i<=count;i++)
	{
		printf("%d ",p[i]);
	}
	printf("\n最优收益：%d",sum+a[0].profile);
}

int main()
{
    struct works w[7] = {{0, 3, 1}, {1, 5, 3}, {2, 20, 4}, {3, 18, 3}, {4, 1, 2}, {5, 6, 1}, {6, 30, 2}};
    int n = 7; 
    sort(w, n);
    printf("作业利润由大到小排序为：\n");
    for(int i = 0; i < n; i++)
	{
        printf("作业%d的时限为: %d,利润为: %d\n", w[i].no,w[i].time,w[i].profile);
    }
    push(w,n);
    return 0;
}
