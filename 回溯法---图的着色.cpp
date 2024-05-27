#include <iostream>

using namespace std;

bool Color(int a[4][4], int *x, int k)
{
    for (int i = 0; i < k; i++)
    {
        if (a[i][k] == 1 && x[i] == x[k])
            return false;
    }
    return true;
}

void Search(int a[4][4], int *x, int k, int m, int n)
{
    if (k == n)
    {
    	cout << "着色方案：";
        for (int i = 0; i < n; i++)
        {
            cout << x[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int j = 1; j <= m; j++)
    {
        x[k] = j;
        if (Color(a, x, k))
        {
            Search(a, x, k + 1, m, n);
        }
    }
}

int main()
{
    int a[4][4] = {
        {0,1,0,1},
        {1,0,1,1},
        {0,0,1,1},
        {1,1,1,0} };
        
    int x[4];
    int m = 3;
    int n = 4;
    
    Search(a, x, 0, m, n);
    
    return 0;
}
