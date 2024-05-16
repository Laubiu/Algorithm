#include <stdio.h>
int search(int s[],int x,int left,int right,int flag)
{
	int count=0;
	int m=(left+right)/2;
	while(left<=right)
	{
		if(x<s[m])
		{
			right=m;
			m=(left+right)/2;
			search(s,x,left,right,flag+1);
			count++;
		}
		else if(x>s[m])
		{
			left=m;
			m=(left+right)/2;
			search(s,x,m,right,flag+1);
			count++;
		}
		else
		{
			x=s[m];
			count++;
			if(flag==0)
			{
				printf("在第%d位查找到了该数字\n",m+1);
				printf("总共查找了%d次",count);
			}
			break;
		}
	}
}

int main()
{
    int s[9]={1,2,3,5,7,9,10,15,16};
    int left=0;
    int right=8;
    int x=15;
    search(s,x,left,right,0);
	return 0;
}
