#include <stdio.h>
#include <string.h>

int search(char *str, char x, int index)
{
    if (str[index] == '\0') // �ж��Ƿ񵽴��ַ�����β
    {
    	printf("���ַ�����û�ҵ����Ҷ���\n");
        return 0;
    }
    if (str[index] == x)
    {
    	printf("���ַ������ҵ��˲��Ҷ���\n");
        return 1;
    }
    return search(str, x, index + 1); // �ݹ���ã�������һ������ֵ
}

int Sum(char *str,char x,int index)
{
	if (str[index] == '\0') // �ж��Ƿ񵽴��ַ�����β
	{
	   	return 0;
	}
	if (str[index] == x)
	{
		return 1 + Sum(str, x, index + 1);
	}
    return Sum(str, x, index + 1); // �ݹ���ã�������һ������ֵ
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
    printf("���ַ�һ��������%d��\n",sum);
    delete(a,x,i);
    printf("ɾ��֮����ַ���Ϊ��\n%s",a);
    return 0;
}
