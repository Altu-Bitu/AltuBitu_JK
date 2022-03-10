#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci; 

int bfs(int h, int w, vector<vector<int>> matrix)
{
	// 상하좌우 대각선
	int dh[8] = { -1, 1, 0, 0, -1, -1, 1, 1};
	int dw[8] = { 0, 0, -1, 1, -1, 1, -1, 1};

	int cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (matrix[i][j] == 1)
			{
				queue<ci> q;
				q.push(ci(i, j));
				while (!q.empty()) {
					int ch = q.front().first;
					int cw = q.front().second;
					matrix[ch][cw] = 2;
					q.pop();
					for (int k = 0; k < 8; k++) {
						int nh = ch + dh[k];
						int nw = cw + dw[k];
						if (nh >= 0 && nh < h && nw >= 0 && nw < w && matrix[nh][nw] == 1) {
							matrix[nh][nw] = 2;
							q.push(ci(nh, nw));
						}
					}
				}
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	int w, h;
	while (true)
	{
		cin >> w >> h;
		// 종료 조건
		if (w == 0 || h == 0)
			break;
		// 지도 입력
		vector<vector<int>> matrix(h, vector<int>(w, 0));
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> matrix[i][j];
		// 연산 & 출력
		cout << bfs(h, w, matrix) << '\n';
	}
	return 0;
}