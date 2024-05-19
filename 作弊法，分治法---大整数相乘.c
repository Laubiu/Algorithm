#include <stdio.h>
//int类最大只能输出2147483647，显然不够大整数相乘结果位数
long long int shorten(long long int a, long long int b, int n) {
    if (n == 1) {
        return a * b;
    } 
	else 
	{
        // 计算10的幂
        long long int power = 1;
        for (int i = 0; i < n / 2; i++) 
		{
            power *= 10;
        }
        
        //拆分为四个位次
        long long int a_high = a / power;
        long long int a_low = a % power;
        long long int b_high = b / power;
        long long int b_low = b % power;
        
        //计算四个乘积
        long long int p1 = shorten(a_high, b_high, n / 2);
        long long int p2 = shorten(a_high, b_low, n / 2);
        long long int p3 = shorten(a_low, b_high, n / 2);
        long long int p4 = shorten(a_low, b_low, n / 2);
        
        //返回计算结果
        long long int result = p1 * power * power + (p2 + p3) * power + p4;
        return result;
    }
}

int main() {
    long long int a = 1234;
    long long int b = 5678;
    long long int result1 = shorten(a, b, 4);
    printf("%lld与%lld相乘的结果为：",a,b);
    printf("%lld\n", result1);
    
    long long int c = 12345678;
    long long int d = 87654321;
    long long int result2 = shorten(c, d, 8);
    printf("\n%lld与%lld相乘的结果为：",c,d);
    printf("%lld", result2);
    
    return 0;
}
