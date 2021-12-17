//래퍼런스 https://wizii.tistory.com/27

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };

pair<int, pair<int, int>> moveCards(int card, vector<vector<int>> &board, int r, int c)
{
	vector<vector<bool>>check(4, vector<bool>(4, false));
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, {r, c} });
	check[r][c] = true;
	while (!q.empty())
	{
		int cnt = q.front().first;
		int cr = q.front().second.first;
		int cc = q.front().second.second;
		q.pop();
		// 카드를 찾았을 
		if (board[cr][cc] == card)
		{
			board[cr][cc] = 0;
			return { cnt + 1, {cr, cc} };
		}
		// 방향키 (한 칸)
		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (nr >= 0 && nr < 4 && nc >= 0 && nc < 4)
			{
				if (!check[nr][nc]) {
					check[nr][nc] = true;
					q.push({ cnt + 1, {nr, nc} });
				}
			}
		}
		// ctrl + 방향키
		for (int i = 0; i < 4; i++) {
			int nr = cr;
			int nc = cc;
			while (nr + dr[i] >= 0 && nr + dr[i] < 4 && nc + dc[i] >= 0  && nc + dc[i] < 4) {
				nr += dr[i];
				nc += dc[i];
				if (board[nr][nc]) // 가장 가까운 카드를 만났을 때
					break;
			}
			if (!check[nr][nc]) {
				check[nr][nc] = true;
				q.push({ cnt + 1, {nr, nc} });
			}
		}
	}
}

int solution(vector<vector<int>> board, int r, int c) {
	int answer = 2147483647;
	// 남은 카드의 개수
	set<int> s;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (board[i][j] != 0)
				s.insert(board[i][j]);
	vector<int> cards(s.begin(), s.end());
	// 모든 경우의 수
	pair<int, pair<int, int>> moved;
	do {
		vector<vector<int>> game_board = board;
		int min_moves = 0;
		int tr = r, tc = c;
		for (int i = 0; i < cards.size(); i++) {
			// 첫 번째 카드
			moved = moveCards(cards[i], game_board, tr, tc); // 최단 경로
			min_moves += moved.first;
			tr = moved.second.first;
			tc = moved.second.second;
			// 두 번째 카드
			moved = moveCards(cards[i], game_board, tr, tc); // 최단 경로
			min_moves += moved.first;
			tr = moved.second.first;
			tc = moved.second.second;
		}
		answer = min(min_moves, answer);
	} while (next_permutation(cards.begin(), cards.end()));
	return answer;
}

int main()
{
	vector<vector<int>> board = { {1, 0, 0, 3}, {2, 0, 0, 0}, {0, 0, 0, 2}, {3, 0, 1, 0} };
	//vector<vector<int>> board = { {3, 0, 0, 2}, {0, 0, 1, 0}, {0, 1, 0, 0}, {2, 0, 0, 3} };
	int r = 1, c = 0;
	//int r = 0, c = 1;
	cout << solution(board, r, c) << '\n';
}
