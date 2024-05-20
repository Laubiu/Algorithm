#include <stdio.h>
//int�����ֻ�����2147483647����Ȼ������������˽��λ��
long long int shorten(long long int a, long long int b, int n) {
    if (n == 1) {
        return a * b;
    } 
	else 
	{
        // ����10����
        long long int power = 1;
        for (int i = 0; i < n / 2; i++) 
		{
            power *= 10;
        }
        
        //���Ϊ�ĸ�λ��
        long long int a_high = a / power;
        long long int a_low = a % power;
        long long int b_high = b / power;
        long long int b_low = b % power;
        
        //�����ĸ��˻�
        long long int p1 = shorten(a_high, b_high, n / 2);
        long long int p2 = shorten(a_high, b_low, n / 2);
        long long int p3 = shorten(a_low, b_high, n / 2);
        long long int p4 = shorten(a_low, b_low, n / 2);
        
        //���ؼ�����
        long long int result = p1 * power * power + (p2 + p3) * power + p4;
        return result;
    }
}

int main() {
    long long int a = 1234;
    long long int b = 5678;
    long long int result1 = shorten(a, b, 4);
    printf("%lld��%lld��˵Ľ��Ϊ��",a,b);
    printf("%lld\n", result1);
    
    long long int c = 12345678;
    long long int d = 87654321;
    long long int result2 = shorten(c, d, 8);
    printf("\n%lld��%lld��˵Ľ��Ϊ��",c,d);
    printf("%lld", result2);
    
    return 0;
}
