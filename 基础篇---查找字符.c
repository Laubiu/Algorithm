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
	printf("在字符串中找到了该字符\n");
	else
	printf("在字符串中没找到\n");
	return 0;
}
int main()
{
	char s[] = "yuwrkjshsfds";
	int n = strlen(s);
	char x = 'l';
	search(s,x,n);
	char y = 'y';
	search(s,y,n);
	return 0;
}
