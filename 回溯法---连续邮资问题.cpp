#include <iostream>

using namespace std;

void Search(int *x, int *y, int k, int n, int m, int all)
{
	if (k == m)
	{
		int sum = 0;
		cout << "可行方案为：";
		for (int i =0; i < m; i++)
		{
			cout << y[i] << " ";
			sum = sum + y[i];
		}
		cout << endl << "总邮值为：" << sum;
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
	cout << "邮票的面值有几种：";
	cin >> n;
	cout << endl;
	cout << "每张信封上可以贴几张邮票：";
	cin >> m;
	cout << endl;
	cout << "--请输入具体邮票面值大小--" << endl;
	int x[n];
	for(int i = 0; i < n; i++)
	{
		cout << "邮票" << i + 1 << "的面值为：";
		cin >> x[i];
	}
	cout << endl;
	int all;
	cout << "最大连续邮资区间是1至";
	cin >> all;
	int y[m] = {0};
	
	Search(x,y,0,n,m,all);
	
	return 0;
}
