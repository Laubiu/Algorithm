#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool Judge(char *str,int n)
{
	if(n==0||n==1)//����orż��λ
	return true;
	if(str[0]!=str[n-1])
		return false;
	else
	    return Judge(str+1,n-2);
}

void Print(char *str)
{
	printf("%s���жϽ��Ϊ��\n",str);
	int n=strlen(str);
	if(Judge(str,n))
	{
		printf("%s�ǻ�����",str);
	}
	else
	{
		printf("%s���ǻ�����",str);
	}
}

int main()
{
	char a[]="abc";
	Print(a);
	printf("\n");
	char b[]="a";
	Print(b);
	printf("\n");
	char c[]="abcba";
	Print(c);
	printf("\n");
	char d[]="abccba";
	Print(d);
	return 0;
}
