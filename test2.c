//��ͨ����
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
	printf("���ַ������ҵ��˸��ַ�");
	else
	printf("���ַ�����û�ҵ�");
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

//��ͨ�۰����
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
	printf("�ڵ�%dλ���ҵ��˸�����\n",m+1);
	printf("������%d��",count);
	return 0;
}

-------------------------------------------------------

//�ݹ�԰����
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
				printf("�ڵ�%dλ���ҵ��˸�����\n",m+1);
				printf("�ܹ�������%d��",count);
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
