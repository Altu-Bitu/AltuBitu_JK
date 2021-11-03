#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, pair<int, int>> ci;
const int INF = 1e5;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

// 다익스트라
vector<vector<int>> dijkstra(int vertex, int startx, int starty, vector<vector<int>>& cave)
{
	vector<vector<int>> dist(vertex, vector<int>(vertex, INF));
	priority_queue<ci, vector<ci>, greater<>> pq; // first : 도둑루피, second : 좌표

	// 시작 위치 초기화
	dist[startx][starty] = cave[0][0];
	pq.push({ cave[0][0], { startx, starty } });

	while (!pq.empty()) {
		int weight = pq.top().first;
		int xpos = pq.top().second.first;
		int ypos = pq.top().second.second;
		pq.pop();
		if (weight > dist[xpos][ypos]) // 이미 확인했던 정점
			continue;
		for (int i = 0; i < 4; i++) 
		{
			int next_xpos = xpos + dx[i];
			int next_ypos = ypos + dy[i];

			if (next_xpos >= 0 && next_xpos < vertex && next_ypos >= 0 && next_ypos < vertex)
			{
				int next_weight = weight + cave[next_xpos][next_ypos];
				if (dist[next_xpos][next_ypos] > next_weight) {
					dist[next_xpos][next_ypos] = next_weight;
					pq.push({ dist[next_xpos][next_ypos], {next_xpos, next_ypos } });
				}
			}
		}
	}
	return dist;
}

int main() 
{
	int n,cnt = 0;
	while (true)
	{
		cin >> n;
		if (n == 0)
			return 0;
		vector<vector<int>> cave(n, vector<int> (n, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> cave[i][j];
		vector<vector<int>> ans = dijkstra(n, 0, 0, cave);
		cout << "Problem " << ++cnt << ": " << ans[n-1][n-1] <<'\n';
	}
}