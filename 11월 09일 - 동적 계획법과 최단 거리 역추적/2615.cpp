#include <iostream>
#include <vector>

using namespace std;

// 좌하향 대각선, 여섯 알(지나 온 바둑돌 확인), 좌햐향 대각선일 때 가장 왼쪽을 출력

vector<vector<int>> board;

// 가로, 세로, 우하향, 좌하향 대각선
int dr[4] = { 1, 0, 1, 1 };
int dc[4] = {0, 1, 1, -1};


vector<int> check(int r, int c)
{
	for (int i = 0; i < 4; i++)
	{
		bool is_six = false;
		int is_five = 0;
		int row = r, col = c;
		for (int j = 0; j < 5; j++)
		{
			if (row + dr[i] >= 0 && row + dr[i] < 19 && col + dc[i] >= 0 && col + dc[i] < 19)
			{
				row += dr[i];
				col += dc[i];
				if (j != 4 && board[row][col]== board[r][c])
					is_five++;
				// 여섯 알 이상
				if (j == 4 && board[row][col] == board[r][c])
					is_six = true;
				// 이전 바둑돌 확인
				if (r - dr[i] >= 0 && r - dr[i] < 19 && c - dc[i] >= 0 && c - dc[i] < 19)
				{
					if (board[r - dr[i]][c - dc[i]] == board[r][c])
						is_six = true;
				}
			}
			else 
				break;
		}
		if (is_five == 4 && !is_six)
		{
			if (i != 3)
				return { board[r][c], r + 1, c + 1 };
			// 좌하향 대각선의 경우 왼쪽 (여섯번 확인 했으므로 한번 더해야 한다)
			else
				return { board[r][c], row - dr[i] + 1, col - dc[i] + 1 };
		}
			
	}
	return { 0, 0, 0 };
}

vector<int> solution()
{
	for (int i = 0; i < 19; i++) 
	{
		for (int j = 0; j < 19; j++)
		{
			if (board[i][j] != 0)
			{
				vector<int> win = check(i, j);
				if (win[0] != 0)
					return win;
			}
		}
	}
	return { 0, 0, 0 };
}

int main()
{
	int black, white;
	board.assign(19, vector<int>(19, 0));
	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			cin >> board[i][j];
	vector<int> ans(3, 0);
	ans = solution();
	if (ans[0] == 0)
		cout << ans[0] <<'\n';
	else
		cout << ans[0] << '\n' << ans[1] << ' ' << ans[2] << '\n';
}
