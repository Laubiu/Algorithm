#include <iostream>

using namespace std;

void Search(int *x, int *y, int k, int n, int m, int all)
{
	if (k == m)
	{
		int sum = 0;
		cout << "���з���Ϊ��";
		for (int i =0; i < m; i++)
		{
			cout << y[i] << " ";
			sum = sum + y[i];
		}
		cout << endl << "����ֵΪ��" << sum;
		cout << endl;
		return;
	}
	
	for (int j = 0; j < n; j++)
	{
		if(all - y[k] >= 0)
		{
			y[k] = x[j];
			Search(x, y, k + 1, n, m, all - y[k]);
		}
	}
}

int main()
{
	int n,m;
	cout << "��Ʊ����ֵ�м��֣�";
	cin >> n;
	cout << endl;
	cout << "ÿ���ŷ��Ͽ�����������Ʊ��";
	cin >> m;
	cout << endl;
	cout << "--�����������Ʊ��ֵ��С--" << endl;
	int x[n];
	for(int i = 0; i < n; i++)
	{
		cout << "��Ʊ" << i + 1 << "����ֵΪ��";
		cin >> x[i];
	}
	cout << endl;
	int all;
	cout << "�����������������1��";
	cin >> all;
	int y[m] = {0};
	
	Search(x,y,0,n,m,all);
	
	return 0;
}
