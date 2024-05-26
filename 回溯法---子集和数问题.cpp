#include <iostream>

using namespace std;

void Search(int *x, int *y, int k, int j, int n, int m)
{
    if(m == 0)
    {
        // 基本条件：如果找到一个和为 m 的子集，打印子集。
        for(int i = 0; i < j; i++)
        {
            cout << y[i] << " ";
        }
        cout << endl;
        return;
    }
    
    if (k < n)
    {
        if(m - x[k] >= 0)
        {
            y[j] = x[k]; 
            // 尝试包含当前元素 x[k] 的情况。
            Search(x, y, k + 1, j + 1, n, m - x[k]); 
        }
        // 尝试不包含当前元素 x[k] 的情况------回溯到上一个节点情况。
        Search(x, y, k + 1, j, n, m);
    }
}

int main()
{
    int x[] = {5, 10, 12, 13, 15, 18};
    int len = sizeof(x) / sizeof(x[0]);
    int *y = new int[len];
    int m = 30;
    
    Search(x, y, 0, 0, len, m);
    
    delete[] y;
    return 0;
}
