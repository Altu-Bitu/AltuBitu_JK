#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// 최대로 블록 옮기는 시간: 256*2*500*500 = 2^27 (거의)
	int n, m, b, height, min_time = 256 * 2 * 500 * 500;
	// 입력
	cin >> n >> m >> b;
	vector<vector<int>> ground(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> ground[i][j];
	}
	// 연산 (브루트포스) (256 포함)
	for (int i = 0; i <= 256; i++)
	{
		int surplus = b, deficit = 0;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				// 블록 제거
				if (ground[j][k] > i)
					surplus += (ground[j][k] - i);
				else // 블록 쌓기
					deficit += (i - ground[j][k]);
			}
		}
		if (surplus >= deficit)
		{
			// b개는 원래 인벤토리에 있던 양이므로 제외
			int time = (surplus - b) * 2 + deficit;
			// 답이 여러 개라면 가장 높은 것, 등호
			if (min_time >= time)
			{
				min_time = time;
				height = i;
			}
		}
	}
	// 출력
	cout << min_time << ' ' << height << '\n';
}