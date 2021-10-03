#include <iostream>
#include <vector>

using namespace std;

int n, l;
vector<pair<int, char>> d(l, { 0, ' ' });
// 오른쪽: 0 아래: 1 왼쪽: 2 위: 3
vector<pair<int, int>> move_dir = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

bool inRange(int a, int b)
{
	if (a < 0 || a >= n || b < 0 || b >= n)
		return false;
	return true;
}

int dummy(vector<vector<int>> board)
{
	int cnt = 0, d_cnt = 0, curr_dir = 0, apple = 0;
	char turn_d = ' ';
	int tail_length = 1, head_length = 1, r_tail = 0, c_tail = 0, r_head = 0, c_head = 0;
	board[0][0] = 1;
	while (true)
	{
		// 시간 증가
		cnt++;
		// 뱀 머리 이동
		if (!inRange(r_head + move_dir[curr_dir].first, c_head + move_dir[curr_dir].second) || board[r_head + move_dir[curr_dir].first][c_head + move_dir[curr_dir].second] > 0)
			return cnt;
		else
		{
			r_head += move_dir[curr_dir].first;
			c_head += move_dir[curr_dir].second;
			apple = board[r_head][c_head] == -1 ? 1 : 0;
			board[r_head][c_head] = ++head_length;
		}
		if (apple == 0) // 사과를 못 먹은 경우 몸 길이 유지
		{
			board[r_tail][c_tail] = 0;
			tail_length++;
			for (int i = 0; i < 4; i++)
			{
				if (inRange(r_tail + move_dir[i].first, c_tail + move_dir[i].second) && board[r_tail + move_dir[i].first][c_tail + move_dir[i].second] == tail_length)
				{
					r_tail += move_dir[i].first;
					c_tail += move_dir[i].second;
					break;
				}
			}
		}
		// 뱀의 방향 변환 정보
		if (d_cnt < l)
		{
			if (d[d_cnt].first == cnt)
			{
				turn_d = d[d_cnt].second;
				d_cnt++;
				if (turn_d == 'L')
					curr_dir = curr_dir == 0 ? 3 : curr_dir - 1;
				else if (turn_d == 'D')
					curr_dir = curr_dir == 3 ? 0 : curr_dir + 1;
			}
		}
	}
}

int main()
{
	int k;
	cin >> n >> k;
	vector<vector<int>> board(n, vector<int>(n, 0));
	int row, col, x;
	char c;
	// 사과
	for (int i = 0; i < k; i++)
	{
		cin >> row >> col;
		board[row-1][col-1] = -1;
	}
	// 방향
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		cin >> x >> c;
		d.push_back(make_pair(x, c));
	}
	cout << dummy(board) << '\n';
}