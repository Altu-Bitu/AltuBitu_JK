#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, score = 0;
	vector<string> v;
	vector<pair<string, int>> t;
	cin >> n;
	v.assign(n, "");
	t.assign(n, {});
	// 입력
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++)
		cin >> t[i].first;
	// 순서
	for (int i = 0; i < n; i++)
	{
		auto iter = find(v.begin(), v.end(), t[i].first);
		t[i].second = (iter - v.begin());
	}
	// 맞은 개수
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (t[i].second < t[j].second)
				score++;
		}
	}
	cout << score << '/' << n * (n - 1) / 2 << '\n';
}