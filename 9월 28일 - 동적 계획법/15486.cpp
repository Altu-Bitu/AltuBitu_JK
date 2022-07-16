#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 14501 보다 N의 범위가 크다 (1500000)
int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	v.assign(n, {});
	// 입력
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	vector<int> dp(1500001, 0);
	for(int i=0; i<n; i++)
	{
		// 상담 한다
		dp[i + v[i].first] = max(dp[i + v[i].first], dp[i] + v[i].second);
		// 상담 안 한다
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}
	cout << dp[n] << '\n';
}