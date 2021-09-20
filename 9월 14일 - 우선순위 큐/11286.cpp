#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct cmp
{
	bool operator()(int x1, int x2)
	{
		if (abs(x1) == abs(x2))
			return x1 > x2;
		return abs(x1) > abs(x2);
	}
};

int main()
{
	int n, x;
	cin >> n;
	priority_queue<int, vector<int>, cmp> pq;
	while (n--)
	{
		cin >> x;
		if (x != 0)
			pq.push(x);
		else
		{
			if (pq.empty())
				cout << 0 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}
	return 0;
}