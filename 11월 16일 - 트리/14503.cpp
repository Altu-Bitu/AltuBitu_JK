#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> space;
int n, m, r, c, d;
// 0: 북, 1: 서, 2: 남, 3: 동 (반시계)
int direction[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int clean_space = 0;

pair<int, pair<int, int>> searchSpace(int x, int y, int dir)
{
	int cnt = 0;
	dir = (dir + 1) % 4;
	while (space[y + direction[dir][0]][x + direction[dir][1]] != 0 && cnt < 4)
	{
		dir = (dir + 1) % 4;
		cnt++;
	}
	if (cnt == 4)
	{
		dir = (dir + 3) % 4;
		x += direction[(dir + 2) % 4][1];
		y += direction[(dir + 2) % 4][0];
		if (space[y][x] == 1)
			return { -1, {-1, -1} }; // d
		else
			return { dir, {x, y} }; // c
	}
	x += direction[dir][1];
	y += direction[dir][0];
	space[y][x] = 2;
	clean_space++;
	return { dir, {x, y} };
}

int solution()
{
	int x = c, y = r, dir = d;
	space[y][x] = 2; // 현재 위치를 청소
	clean_space++;
	while (true)
	{
		pair<int, pair<int, int>> coord = searchSpace(x, y, dir);
		if (coord.second.first == -1 && coord.second.second == -1) // d
			break;
		x = coord.second.first;
		y = coord.second.second;
		dir = coord.first;
	}
	return clean_space;
}

int main()
{
	// 입력
	cin >> n >> m;
	space.assign(n, vector<int>(m, 0));
	cin >> r >> c >> d;
	if (d == 1) d = 3;
	else if (d == 3) d = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> space[i][j];
	// 연산 & 출력
	cout << solution() << '\n';
}
