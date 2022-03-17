#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void lcs(string s1, string s2) {
	vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
	for (int i = 1; i < s1.size() + 1; i++)
	{
		for (int j = 1; j < s2.size() + 1; j++)
		{
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	// DP 배열
	/*
	for (int i = 1; i < s1.size() + 1; i++)
	{
		for (int j = 1; j < s2.size() + 1; j++)
		{
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
	int idx = 0;
	string ans = "";
	int i = s1.size(), j = s2.size();
	// 오른쪽 아래부터 시작해서 같은 숫자 중 가장 왼쪽 위에 있는 곳으로 이동
	while (i)
	{
		if (dp[i][j] == 0) break;
		if (dp[i][j] == dp[i - 1][j])
			i--;
		else
		{
			while (dp[i][j] != dp[i - 1][j])
				j--;
			// cout << i << ' ' << j << '\n';
			ans = s2[j] + ans;
		}
	}	
	cout << dp[s1.size()][s2.size()] << '\n' << ans << '\n';
}

int main()
{
	// 입력
	string s1, s2;
	cin >> s1 >> s2;
	// 연산 & 출력
	lcs(s1, s2);
	return 0;
}