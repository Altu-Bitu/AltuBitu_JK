#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// sort와는 반대로 해야 함 (오름차순, 내림차순)
struct compare
{
	bool operator()(pair<int, int>& p1, pair<int, int>& p2)
	{
		if (p1.second != p2.second)
			return p1.second > p2.second;
		return p1.first > p2.first;
	}
};

bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
	if (p1.first != p2.first)
		return p1.first < p2.first;
	return p1.second < p2.second;
}

int main()
{
	int n, s, t;
	cin >> n;
	vector<pair<int, int>> p;
	priority_queue<pair<int,int>, vector<pair<int, int>>, compare> pq;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> t;
		p.push_back(make_pair(s, t));
	}
	sort(p.begin(), p.end(), cmp);
	pq.push(p[0]);
	for (int i = 1; i < n; i++)
	{
		if (pq.top().second > p[i].first)
			pq.push(p[i]);
		else
		{
			pq.pop();
			pq.push(p[i]);
		}
	}
	cout << pq.size();
	return 0;
}