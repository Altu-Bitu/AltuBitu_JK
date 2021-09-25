#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int n;
vector<int> v;
map<int, int> m;

bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
	if (p1.second == p2.second)
		return p1.first < p1.first;
	return p1.second > p2.second;
}

int mean()
{
	int sum = 0;
	sum = accumulate(v.begin(), v.end(), 0);
	 return round((float)sum / n);
}

int median()
{
	return v[n / 2];
}

int mode()
{
	vector <pair<int, int>> cnt;
	for (auto iter = m.begin(); iter != m.end(); iter++)
		cnt.push_back(make_pair(iter->first, iter->second));
	sort(cnt.begin(), cnt.end(), cmp);
	if ((cnt.size() == 1) || cnt[0].second != cnt[1].second)
		return cnt[0].first;
	else
		return cnt[1].first;
}

int range()
{
	return v[v.size() - 1] - v[0];
}

int main()
{
	cin >> n;
	v.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		m[v[i]]++;
	}
	sort(v.begin(), v.end());
	cout << mean() << '\n';
	cout << median() << '\n';
	cout << mode() << '\n';
	cout << range() << '\n';
	return 0;
}