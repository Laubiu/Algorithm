#include <iostream>
#include <vector>

using namespace std;

void Search(int *x, vector<int> &y, int k, int n, int m, int all)
{
    if (k > m)
    {
        return;
    }
    
    if (k == m)
    {
        int sum = 0;
        cout << "可行方案为：";
        for (int i = 0; i < k; i++)
        {
            cout << y[i] << " ";
            sum += y[i];
        }
        cout << endl << "总邮值为：" << sum << endl << endl;
    }
    
    for (int j = 0; j < n; j++)
    {
        if (all - x[j] >= 0)
        {
            y[k] = x[j];
            Search(x, y, k + 1, n, m, all - x[j]);
        }
    }
}

int main()
{
    int n, max_m;
    cout << "邮票的面值有几种：";
    cin >> n;
    cout << endl;
    
    cout << "每张信封上最多可以贴几张邮票：";
    cin >> max_m;
    cout << endl;
    
    cout << "请输入具体邮票面值大小：" << endl;
    int x[n];
    for (int i = 0; i < n; i++)
    {
        cout << "邮票" << i + 1 << "的面值为：";
        cin >> x[i];
    }
    cout << endl;
    
    int all;
    cout << "最大连续邮资区间是 1 至 ";
    cin >> all;
    cout << endl;
    
    vector<int> y(max_m);
    
    for (int m = 1; m <= max_m; m++)
    {
        cout << m << " 张邮票的组合：" << endl;
        Search(x, y, 0, n, m, all);
    }
    
    return 0;
}
