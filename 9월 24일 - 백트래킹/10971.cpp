// Traveling Salesman problem (TSP)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 10;

int n, min_cost = 10000000;
bool check_visited[SIZE + 1];
vector<vector<int>> w;

void backtracking(int start, int end, int cnt, int cost)
{
	// 모든 도시를 다 방문했는가
	if (cnt == n-1) {
		// 마지막 도시로 가는 길이 존재하는가
		if (w[start][end] != 0)
		{
			cost += w[start][end];
			// 최소값 갱신
			min_cost = min(min_cost, cost);
		}
		return;
	}
	// 도시를 하나씩 방문
	for (int i = 0; i < n; i++) {
		// 한번도 방문하지 않았고 가는 길이 있는 도시로만 이동
		if (!check_visited[i]  && w[start][i] != 0) {
			check_visited[i] = true;
			cnt++;
			//cout << "cnt:" << cnt << " i:" << i << " end:" << end << " cost:" << cost << '\n';
			//for (int t = 0; t < n; t++)
			//	cout << check_visited[t];
			//cout << '\n';
			backtracking(i, end, cnt, cost + w[start][i]);
			check_visited[i] = false;
			cnt--;
		}
	}
}

int main()
{
	cin >> n;
	w.assign(n, vector<int>(n, 0));
	// 입력
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];
	// 시작 도시 별로 비용 계산 (시작에서 다시 시작으로 오도록)
	for (int c = 0; c < n; c++)
	{
		check_visited[c] = true;
		backtracking(c, c, 0, 0);
		check_visited[c] = false;
	}
	// 출력
	cout << min_cost << '\n';
	return 0;
}