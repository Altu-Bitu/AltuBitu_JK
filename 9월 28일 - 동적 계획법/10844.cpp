#include <iostream>
#include <vector>

using namespace std;

#define DIV 1000000000;

int main()
{
	int n, ans = 0;
	cin >> n;
	vector<vector<int>> dp(100, vector<int>(10,0));
	// 한 자리 수
	for (int i = 0; i < 10; i++)
		dp[0][i] = 1;
	// i: 자리의 수, j: 일의 자리 수 
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0) // 일의 자리 수가 0
				dp[i][0] = dp[i - 1][1];
			else if (j == 9) // 일의 자리 수가 9
				dp[i][9] = dp[i - 1][8];
			else // 일의 자리 수가 1~8
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] = dp[i][j] % DIV;
		}
	}
	/*
	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < 10; b++)
			cout << dp[a][b] << ' ';
		cout << '\n';
	}
	cout << '\n';
	*/
	// 0으로 시작하는 것 제외
	for (int i = 1; i < 10; i++)
		ans = (ans + dp[n-1][i]) % DIV;
	cout << ans <<'\n';
	return 0;
}