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
        cout << "���з���Ϊ��";
        for (int i = 0; i < k; i++)
        {
            cout << y[i] << " ";
            sum += y[i];
        }
        cout << endl << "����ֵΪ��" << sum << endl << endl;
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
    cout << "��Ʊ����ֵ�м��֣�";
    cin >> n;
    cout << endl;
    
    cout << "ÿ���ŷ�����������������Ʊ��";
    cin >> max_m;
    cout << endl;
    
    cout << "�����������Ʊ��ֵ��С��" << endl;
    int x[n];
    for (int i = 0; i < n; i++)
    {
        cout << "��Ʊ" << i + 1 << "����ֵΪ��";
        cin >> x[i];
    }
    cout << endl;
    
    int all;
    cout << "����������������� 1 �� ";
    cin >> all;
    cout << endl;
    
    vector<int> y(max_m);
    
    for (int m = 1; m <= max_m; m++)
    {
        cout << m << " ����Ʊ����ϣ�" << endl;
        Search(x, y, 0, n, m, all);
    }
    
    return 0;
}
