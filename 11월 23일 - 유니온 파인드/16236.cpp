#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 상하좌우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
vector<vector<int>> space;

// 거리(시간)와 좌표를 리턴
pair<int, pair<int, int>> findFish(pair<int, int> shark, int shark_size, int n)
{
	// Min heap으로 구현 (거리, (x, y))
	// 거리가 같으면 x(가장 위), y(가장 왼쪽)가 우선순위에 고려됨
	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,  greater<pair<int, pair<int, int>>>> pq;
	queue<pair<int, pair<int, int>>> q; // 상어로부터 거리, 좌표
	vector<vector<bool>> check(n, vector<bool>(n, false));
	check[shark.first][shark.second] = true;
	q.push({ 1, shark }); 
	while (!q.empty())
	{
		pair<int, pair<int, int>> curr = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			pair<int, pair<int, int>> next = { curr.first, { curr.second.first + dx[i], curr.second.second + dy[i] } };
			if (next.second.first >= 0 && next.second.first < n && next.second.second >= 0 && next.second.second < n)
			{
				if (check[next.second.first][next.second.second] == true)
					continue;
				check[next.second.first][next.second.second] = true;
				if (space[next.second.first][next.second.second] > shark_size)
					continue;
				// 더 작은 물고기 (먹이 후보)
				if (space[next.second.first][next.second.second] != 0 && space[next.second.first][next.second.second] < shark_size)
				{
					pq.push(next);
					continue;
				}
				// 빈칸, 크기 같은 물고기, 더 작은 물고기
				q.push({ next.first + 1, next.second });
			}
		}
	}
	if (pq.empty())
		return { -1, { -1, -1 } };
	space[pq.top().second.first][pq.top().second.second] = 0;
	return pq.top();
}
int main()
{
	int n;
	// 입력
	cin >> n;
	space.assign(n, vector<int>(n, 0));
	pair<int, int> shark;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> space[i][j];
			if (space[i][j] == 9)
			{
				shark.first = i;
				shark.second = j;
				space[i][j] = 0; // 0으로 값 바꿔줌
			}
		}
	}
	// 연산
	queue<pair<int,int>> q;
	q.push(shark);
	int shark_size = 2, cnt = 0, time = 0;
	while (!q.empty())
	{
		pair<int, int> curr = q.front();
		q.pop();
		pair<int, pair<int, int>> fish = findFish(curr, shark_size, n);
		// 엄마 상어에 도움 요청
		if (fish.second.first == -1 && fish.second.second == -1)
			break;
		cnt++; // 먹은 물고기
		time += fish.first;
		// 크기 증가
		if (cnt == shark_size)
		{
			cnt = 0;
			shark_size++;
		}
		q.push({ fish.second.first, fish.second.second });
	}
	// 출력
	cout << time << '\n';
}