#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k, input;
	cin >> n >> k;
	vector<int> coin(100, 0);
	// 동전의 최대 가치 100000만큼 dp 생성
	// 최솟값을 구해야 하므로 10001(k의 최대값보다 큰 값)로 초기화
	vector<int> dp(100001, 10001);
	dp[0] = 0;
	// 코인 값 입력
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	//  최솟값 구하기
	for (int i = 0; i < n; i++)
		for (int j = coin[i]; j <= k; j++)
			dp[j] = min(dp[j], dp[j - coin [i]] + 1);
	// 불가능한 경우 -1 출력
	if (dp[k] == 10001)
		cout << -1 << '\n';
	else
		cout << dp[k] << '\n';
	return 0;
}