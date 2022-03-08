#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef pair<int, int> xy;

int m, n, max_sum = 0;

vector<vector<int>> v;
vector<vector<bool>> visited;

int purple[4][4][2] = {
	{{0, 0}, {0, 1}, {0, 2}, {1, 1}}, //  ㅜ
	{{0, 1}, {1, 0}, {1, 1}, {1, 2}}, // ㅗ
	{{0, 1}, {1, 0}, {1, 1}, {2, 1}}, // ㅓ
	{{0, 0}, {1, 0}, {2, 0}, {1, 1}} // ㅏ
};

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool check_boundary(xy coor) {
	if (coor.first >= 0 && coor.first < n && coor.second >= 0 && coor.second < m)
		return true;
	return false;
}

void backtracking(int x, int y, int cnt, int sum) {
	//cout << "WHERE: " << x << " " << y << "cnt:" << cnt << '\n';
	// 테트로미노는 정사각형 4개이므로
	if (cnt == 4)
	{
		max_sum = max(max_sum, sum);
		return;
	}
	// 상하좌우 확인
	for (int k = 0; k < 4; k++) {
		int nr = x + dx[k];
		int nc = y + dy[k];
		// 범위 내에 있고 아직 방문하지 않은 그리드
		if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc]) {
			sum += v[nr][nc];
			visited[nr][nc] = true;
			cnt++;
			backtracking(nr, nc, cnt, sum);
			sum -= v[nr][nc];
			visited[nr][nc] = false;
			cnt--;
		}
	}
}

void check_purple(int i, int j)
{
	int sum;
	// purple
	for (int p = 0; p < 4; p++)
	{
		string s = "0123";
		// 그냥 while로 하면 0123은 포함하지 않는다.
		// 모든 경우 다 확인
		do
		{
			sum = 0;
			xy c1 = make_pair(purple[p][s[0] - '0'][0] + i, purple[p][s[0] - '0'][1] + j);
			xy c2 = make_pair(purple[p][s[1] - '0'][0] + i, purple[p][s[1] - '0'][1] + j);
			xy c3 = make_pair(purple[p][s[2] - '0'][0] + i, purple[p][s[2] - '0'][1] + j);
			xy c4 = make_pair(purple[p][s[3] - '0'][0] + i, purple[p][s[3] - '0'][1] + j);
			// 범위 내에 있는지 체크
			if (check_boundary(c1) && check_boundary(c2) && check_boundary(c3) && check_boundary(c4))
				sum += (v[c1.first][c1.second] + v[c2.first][c2.second] + v[c3.first][c3.second] + v[c4.first][c4.second]);
			max_sum = max(max_sum, sum);
		} while (next_permutation(s.begin(), s.end()));
	}
}

int main()
{
	// 입력
	cin >> n >> m;
	v.assign(n, vector<int>(m, 0));
	visited.assign(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> v[i][j];
	// 연산
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = true;
			backtracking(i, j, 1, v[i][j]);
			visited[i][j] = false;
			check_purple(i, j);
		}
	}
	cout << max_sum << '\n';
}