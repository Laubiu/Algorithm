#include <iostream>
#include <cmath>

using namespace std;

bool isValid(int *x, int m) 
{
    if (x[0] + x[1] <= x[2] || abs(x[0] - x[1]) >= x[2])
        return false;
    if (x[0] + x[1] + x[2] != m)
        return false;
    return true;
}

void findTriangles(int *x, int m, int depth, int &count) 
{
	if (depth == 3)
	{
        if (isValid(x, m))
		{
            count++;
            cout << "三边长度分别为：" << x[0] << " " << x[1] << " " << x[2] << endl;
        }
        return;
    }
    
    for (int i = 1; i <= m; i++)
	{
		x[depth] = i;
		findTriangles(x, m, depth + 1, count);
	}
}

int main()
{
    int m = 14;
    int *x = new int[3];
    for(int i=0; i<3; i++)
	{
		x[i] = 0;
	}
	
	int count = 0;
	findTriangles(x,m,0,count);
	cout << "周长为" << m <<"的三角形个数是: " << count << endl;
	
	delete[] x;
	return 0;
}
