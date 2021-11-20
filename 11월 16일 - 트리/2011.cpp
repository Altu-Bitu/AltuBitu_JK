#include <iostream>
#include <vector>
#include <string>

#define MAX 5000
#define MOD 1000000

using namespace std;

int solution(string code)
{
	vector<int> dp(MAX, 0);
	if (code[0] == '0') // 첫 숫자가 0
		return 0;
	if (code.length() < 2) // 한 자리 수
		return 1;
	dp[0] = 1;
	// 두 번째 자리
	if (code[1] - '0' != 0)
		dp[1] += 1;
	if (stoi(code.substr(0, 2)) >= 10 && stoi(code.substr(0, 2)) <= 26)
		dp[1] += 1;
	for (int i = 2; i < code.length(); i++)
	{
		if (code[i - 1] == '0' && code[i] == '0') // 연속된 0
			return 0;
		int num = stoi(code.substr(i - 1, 2));
		if(code[i] != '0')
			dp[i] = (dp[i - 1] + dp[i]);
		if (num >= 10 && num <= 26)
			dp[i] = (dp[i - 2] + dp[i]);
		dp[i] %= MOD;
	}
	return dp[code.length() - 1];
}

int main()
{
	// 입력
	string code;
	cin >> code;

	//연산 & 출력
	cout << solution(code) << '\n';
	return 0;
}