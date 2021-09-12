#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> x, x_sort;
map<int, int> m;

void coor_zip(int n)
{
	sort(x_sort.begin(), x_sort.end());
	x_sort.resize(unique(x_sort.begin(), x_sort.end()) - x_sort.begin());
	for (int i = 0; i < x_sort.size(); i++)
		m[x_sort[i]] = i;
	for (int i = 0; i < n; i++)
		cout << m[x[i]] << ' ';
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, input;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		x.push_back(input);
		x_sort.push_back(input);
	}
	coor_zip(n);
}