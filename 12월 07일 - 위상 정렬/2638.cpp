#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, h = 0;
vector<vector<int>> cheese;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void outsideAir()
{
	queue<pair<int, int>> q;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	q.push({ 0,0 }); // 가장자리에는 치즈가 놓이지 않는다.
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (!visited[nx][ny] && (cheese[nx][ny] == 0 || cheese[nx][ny] == 2))
				{
					cheese[nx][ny] = 2;
					visited[nx][ny] = true;	
					q.push({ nx, ny });
				}
			}
		}
	}
}

void melt()
{
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < m - 1; j++)
		{
			int cnt = 0;
			if (cheese[i][j] == 1) // 치즈 녹일지 말지 결정
			{
				for (int d = 0; d < 4; d++)
				{
					int x = i + dx[d];
					int y = j + dy[d];
					if (cheese[x][y] == 2)
						cnt++;
				}
				if (cnt >= 2)
					cheese[i][j] = 0;
			}
		}
	}
}

int main()
{
	// 입력
	cin >> n >> m;
	cheese.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> cheese[i][j];
	// 연산
	while (true)
	{
		// 치즈가 남아있는지 확인
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (cheese[i][j] == 1)
				{
					flag = true;
					break;
				}
			}
			if (flag == true)
				break;
		}
		if (flag == false)
			break;
		// 외부 공기 표시
		outsideAir();
		// 치즈 녹임
		melt();
		h++;
	}
	// 출력
	cout << h << '\n';
}