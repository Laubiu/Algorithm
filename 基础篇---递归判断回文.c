#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool Judge(char *str,int n)
{
	if(n==0||n==1)//奇数or偶数位
	return true;
	if(str[0]!=str[n-1])
		return false;
	else
	    return Judge(str+1,n-2);
}

void Print(char *str)
{
	printf("%s的判断结果为：\n",str);
	int n=strlen(str);
	if(Judge(str,n))
	{
		printf("%s是回文数",str);
	}
	else
	{
		printf("%s不是回文数",str);
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
