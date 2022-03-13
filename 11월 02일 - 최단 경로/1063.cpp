#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, -1, 1, 1, 1, -1, -1};
string km[8] = { "R", "L", "B", "T", "RT", "LT", "RB", "LB" };

string king, rock;

bool check_boundary(int r, int c)
{
	if (r >= 0 && r < 8 && c >= 0 && c < 8)
		return true;
	return false;
}

void solution(int n, vector<string> king_move, vector<char>& pos)
{
	int king_col = king[0] - 'A', king_row =  king[1] - '1', rock_col = rock[0] - 'A', rock_row = rock[1] - '1';
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		for (j = 0; j < 8; j++)
		{
			if (king_move[i] == km[j])
				break;
		}
		// 킹이 움직인 곳에 돌
		if (king_col + dx[j] == rock_col && king_row + dy[j] == rock_row)
		{
			if (check_boundary(king_col + dx[j], king_row + dy[j]) && check_boundary(rock_col + dx[j], rock_row + dy[j]))
			{
				king_row += dy[j];
				king_col += dx[j];
				rock_row += dy[j];
				rock_col += dx[j];
			}
		}
		else
		{
			// 킹의 움직임이 체스판 안쪽
			if (check_boundary(king_col + dx[j], king_row + dy[j]))
			{
				king_row += dy[j];
				king_col += dx[j];
			}
		}
	}

	pos[0] = (char) (king_col + 'A');
	pos[1] = (char) (king_row + '1');
	pos[2] = (char) (rock_col + 'A');
	pos[3] = (char) (rock_row + '1');
}

int main()
{
	vector<char> pos(4, ' ');
	int n;
	// 입력
	cin >> king >> rock >> n;
	vector<string> king_move(n, "");
	for (int i = 0; i < n; i++)
		cin >> king_move[i];

	// 연산
	solution(n, king_move, pos);

	// 출력
	cout << pos[0] << pos[1] << '\n' << pos[2] << pos[3] << '\n';
}