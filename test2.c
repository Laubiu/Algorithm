//普通查找
#include <stdio.h>
#include <string.h>
char search(char *s,char x,int n)
{
	int i,flag=0;
	for(i=0;i<n;i++)
	{
		if(s[i]==x)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	printf("在字符串中找到了该字符");
	else
	printf("在字符串中没找到");
}
int main()
{
	char s[] = "yuwrkjshsfds";
	int n = strlen(s);
	char x = 'l';
	search(s,x,n);
	return 0;
}

---------------------------------------------------

//普通折半查找
#include <stdio.h>
#include <string.h>
int main()
{
	int a[9]={1,2,3,5,7,9,10,15,16};
	int left=0,right=8;
	int m=(left+right)/2;
	int k=15;
	int count=0;
	while(left<=right)
	{
		if(k<a[m])
		{
			right=m;
			m=(left+right)/2;
			count++;
		}
		else if(k>a[m])
		{
			left=m;
			m=(left+right)/2;
			count++;
		}
		else
		{
		    k=a[m];
		    count++;
		    break;
		}
	}
	printf("在第%d位查找到了该数字\n",m+1);
	printf("查找了%d次",count);
	return 0;
}

-------------------------------------------------------

//递归对半查找
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
