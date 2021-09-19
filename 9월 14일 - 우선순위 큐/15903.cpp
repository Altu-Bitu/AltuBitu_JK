#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	priority_queue<long long, vector<long long>, greater<>> pq;
	int n, m, a;
	long long x, y, sum=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		pq.push(a);
	}
	for (int i = 0; i < m; i++)
	{
		x = pq.top(); pq.pop();
		y = pq.top(); pq.pop();
		pq.push(x + y);
		pq.push(x + y);
	}
	while(!pq.empty())
	{
		sum += pq.top();
		pq.pop();
	}
	cout << sum;
	return 0;
}