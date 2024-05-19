#include <stdio.h>
#include <string.h>

int search(char *str, char x, int index)
{
    if (str[index] == '\0') // 判断是否到达字符串结尾
    {
    	printf("在字符串中没找到查找对象\n");
        return 0;
    }
    if (str[index] == x)
    {
    	printf("在字符串中找到了查找对象\n");
        return 1;
    }
    return search(str, x, index + 1); // 递归调用，传递下一个索引值
}

int Sum(char *str,char x,int index)
{
	if (str[index] == '\0') // 判断是否到达字符串结尾
	{
	   	return 0;
	}
	if (str[index] == x)
	{
		return 1 + Sum(str, x, index + 1);
	}
    return Sum(str, x, index + 1); // 递归调用，传递下一个索引值
}

void delete(char *str,char x,int index)
{
	int n=strlen(str);
	if(str[index]=='\0')
	    return;
	if(str[index]==x)
	{
		for(int i=index;i<n;i++)
		{
			str[i]=str[i+1];
		}
		return delete(str,x,index);
	}
	else
	    return delete(str,x,index+1);
	
}

int main()
{
    char a[] = "abcabcaa";
    char x = 'a';
    int i=0;
    search(a,x,i);
    int sum=Sum(a,x,i);
    printf("该字符一共出现了%d次\n",sum);
    delete(a,x,i);
    printf("删除之后的字符串为：\n%s",a);
    return 0;
}
