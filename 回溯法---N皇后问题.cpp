#include <iostream>
#include <cmath> // 添加头文件，用于使用 abs 函数

using namespace std;

bool Place(int k, int i, int *x)
{
    // 判断
    for (int j = 0; j < k; j++)
    {
        if (x[j] == i || (abs(x[j] - i) == abs(j - k)))
            return false;
    }
    return true; 
}

void NQueens(int k, int n, int *x)
{
    for (int i = 0; i < n; i++)
    {
        if (Place(k, i, x))
        {
            x[k] = i;
            if (k == n - 1)
            {
            	cout << "可行方案为:" << endl;
                for (int i = 0; i < n; i++)
                {
                    cout << x[i] << " ";
                }
                cout << endl;
            }
            else
            {
                NQueens(k + 1, n, x);
            }
        }
    }
}

int main()
{
    int n = 4;
    int m = 5;
    int *x = new int[n]; // 动态分配数组内存
    int *y = new int[m];
    // 初始化数组
    for (int i = 0; i < n; i++)
    {
        x[i] = 0;
        y[i] = 0;
    }

    NQueens(0, n, x);
    NQueens(0, m, y);

    delete[] x; // 释放内存
    return 0;
}
