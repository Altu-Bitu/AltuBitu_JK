#include <iostream>

using namespace std;

char star[400][400];

// 정사각형 모양으로 별 찍기 함수
void square(int n, int side)
{
	// n = 1
	if (side == 4 * n - 4)
	{
		star[side][side] = '*';
		return;
	}

	// side 길이에 따라 정사각형 별 찍기
	for (int i = side; i <= 4 * n - 4 - side; i++)
	{
		star[i][side] = '*';
		star[side][i] = '*';
		star[i][4 * n - 4 - side] = '*';
		star[4 * n - 4 - side][i] = '*';
	}
	square(n, side + 2);
}

int main()
{
	int n;
	cin >> n;
	// 배열 초기화
	for (int i = 0; i <= 4 * n - 4; i++)
		for (int j = 0; j <= 4 * n - 4; j++)
			star[i][j] = ' ';

	// 재귀 함수 호출
	square(n, 0);

	// 출력
	for (int i = 0; i <= 4 * n - 4; i++)
	{
		for (int j = 0; j <= 4 * n - 4; j++)
			cout << star[i][j];
		cout << '\n';
	}
}
