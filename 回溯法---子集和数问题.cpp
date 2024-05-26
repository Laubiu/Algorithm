#include <iostream>

using namespace std;

void Search(int *x, int *y, int k, int j, int n, int m)
{
    if(m == 0)
    {
        // ��������������ҵ�һ����Ϊ m ���Ӽ�����ӡ�Ӽ���
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
            // ���԰�����ǰԪ�� x[k] �������
            Search(x, y, k + 1, j + 1, n, m - x[k]); 
        }
        // ���Բ�������ǰԪ�� x[k] �����------���ݵ���һ���ڵ������
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
