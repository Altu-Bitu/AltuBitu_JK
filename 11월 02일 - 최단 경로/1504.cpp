#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5 * 8;

vector<int> dijkstra(int vertex, int start, vector<vector<ci>>& graph)
{
	vector<int> dist(vertex + 1, INF);
	priority_queue<ci, vector<ci>, greater<>> pq;

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int weight = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (weight > dist[node])
			continue;
		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i].first;
			int next_weight = weight + graph[node][i].second;
			if (dist[next_node] > next_weight) {
				dist[next_node] = next_weight;
				pq.push({ next_weight, next_node });
			}
		}
	}
	return dist;
}

int main() {
	int n, e, a, b, c, v1, v2;

	// 입력
	cin >> n >> e;
	vector<vector<ci>> graph(n + 1, vector<ci>(0)); // 인접 리스트
	while (e--) {
		cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}
	cin >> v1 >> v2;

	// 연산
	int start_v1, start_v2, v1_v2, v2_v1, v1_n, v2_n;
	vector<int> ans = dijkstra(n, 1, graph);
	start_v1 = ans[v1]; // 1-> v1
	start_v2 = ans[v2]; // 1-> v2
	ans = dijkstra(n, v1, graph);
	v1_v2 = ans[v2]; // v1->v2
	v1_n = ans[n]; // v1-> n
	ans = dijkstra(n, v2, graph);
	v2_v1 = ans[v1]; // v1->v2
	v2_n = ans[n]; // v2-> n

	bool flag1 = false, flag2 = false;

	if (start_v1 == INF || v1_v2 == INF || v2_v1 == INF)
		flag1 = true;
	if (start_v2 == INF || v2_v1 == INF || v1_v2 == INF)
		flag2 = true;

	if (flag1 && flag2)
		cout << -1 << '\n';
	else if (flag1)
		cout << start_v2 + v2_v1 + v1_n << '\n';
	else if (flag2)
		cout << start_v1 + v1_v2 + v2_n << '\n';
	else
		cout << min(start_v1 + v1_v2 + v2_n, start_v2 + v2_v1 + v1_n) <<'\n';
}