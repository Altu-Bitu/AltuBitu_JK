// 레퍼런스: https://donggoolosori.github.io/2020/11/20/boj-15685/

#include <iostream>
#include <vector>
#include <cmath>
#define MAX 100

using namespace std;

// 0 세대: 0
// 1 세대: 0 1
// 2 세대: 0 1 2 1
// 3 세대: 0 1 2 1 2 3 2 1
// N 세대: concat(N-1세대), ((N-1세대 거꾸로) + 1)%4)

bool plane[MAX+1][MAX+1] = { {false, } };


// 좌표를 왼쪽 위가 (0,0)일 때를 기준
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 }; 

int dragonCurve(int n, vector<vector<int>> & curve)
{
	for (int i = 0; i < n; i++)
	{
		int x = curve[i][0];
		int y = curve[i][1];
		int direction = curve[i][2], generation = curve[i][3], lines = pow(2, generation), k = 1;
		vector<int> v(lines+1, 0); // 방향 저장
		v[0] = direction;
		plane[y][x] = true;
		//cout << "NEW GENERATION" << '\n';
		for (int j = 1; j <= lines; j++)
		{
			x += dx[direction];
			y += dy[direction];
			direction = (v[ pow(2, k) - 1 - j] + 1) % 4; // 대칭성 이용
			v[j] = direction;
			if (x >= 0 && x <= MAX && y >= 0 && y <= MAX)
				plane[y][x] = true;
			//cout << x << ' ' << y << '\n';
			if (j == pow(2, k) - 1)
				k++;
		}
	}
	int ans = 0;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (plane[i][j] && plane[i + 1][j] && plane[i][j + 1] && plane[i + 1][j + 1])
				ans++;
	return ans;
}

int main()
{
	// 입력
	int n;
	cin >> n;
	vector<vector<int>> curve(n, vector<int>(4, 0));
	for (int i = 0; i < n; i++)
		cin >> curve[i][0] >> curve[i][1] >> curve[i][2] >> curve[i][3];
	// 연산 & 출력
	cout << dragonCurve(n, curve) << '\n';
	return 0;
}
