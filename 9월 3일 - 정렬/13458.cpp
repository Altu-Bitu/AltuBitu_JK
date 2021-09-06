#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, b, c;
	vector<int> a;
	cin >> n;
	long long supervisor = n;
	a.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> b >> c;
	for (int i = 0; i < n; i++)
	{
		a[i] -= b;
		if(a[i] >0)
		{ 
			supervisor += a[i] / c;
			if (a[i] % c != 0)
				supervisor += 1;
		}
	}
	cout << supervisor;
}