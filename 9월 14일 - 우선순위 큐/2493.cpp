#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	stack<pair<int, int> > s;
	int n, k;
	vector <int> v;
	cin >> n;
	v.assign(n, 0);
	for(int i=1; i<=n; i++)
	{
		cin >> k;
		while (!s.empty())
		{
			if (s.top().first > k)
			{
				v[i - 1] = s.top().second;
				break;
			}
			else
				s.pop();
		}
		s.push(make_pair(k, i));
	}
	for (int i = 0; i < n; i++)
		cout << v[i] << ' ';
	return 0;
}