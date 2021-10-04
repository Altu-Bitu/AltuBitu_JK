#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m, ans = 0; bool flag = true;
	string input;
	// 입력
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m, 0));
	vector<vector<int>> b(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		for (int j = 0; j < m; j++)
			a[i][j] = input[j] - '0';
	}
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		for (int j = 0; j < m; j++)
			b[i][j] = input[j] - '0';
	}
	// 왼쪽 위 -> 오른쪽 아래 순서로 연산을 수행
	// 한번 지나가면 왼쪽 위 모서리의 값은 다시 검사할 수 없음
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (a[i][j] != b[i][j])
			{
				// 연산
				for (int k = 0; k < 3; k++)
				{
					for (int l = 0; l < 3; l++)
						a[i + k][j + l] ^= 1;
				}
				ans++;
			}
		}
	}
	// A를 B로 바꿀 수 없다면
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] != b[i][j])
			{
				cout << -1 << '\n';
				return 0;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}