#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, sum=0;
	cin >> n;
	vector<int> p;
	p.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	sort(p.begin(), p.end());
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		temp = temp + p[i];
		sum += temp;
	}		
	cout << sum;
}