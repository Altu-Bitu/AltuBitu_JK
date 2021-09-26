#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int n, score = 0;
	map<string, int> m;
	vector<pair<string, int>> t;
	string input;
	cin >> n;
	t.assign(n, {});
	// 입력
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		m[input] = i;
	}
	for (int i = 0; i < n; i++)
		cin >> t[i].first;
	// 순서
	for (int i = 0; i < n; i++)
		t[i].second = m[t[i].first];
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
