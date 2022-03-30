#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 위상정렬
vector<vector<int>> topologicalSort(int n, vector<int>& indegree, vector<vector<pair<int, int>>>& graph) {
	vector<vector<int>> result(n + 1, vector<int>(n+1, 0));
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (!indegree[i]) // 기본 부품
		{
			q.push(i);
			result[i][i] = 1; // i번째 부품을 만드는데 필요한 
		}
	}

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int i = 0; i < graph[node].size(); i++)
		{
			int next_node = graph[node][i].first;
			for(int j=1; j<=n; j++)
				result[j][next_node] += result[j][node] * graph[node][i].second;
			// cout << result[next_node] << '\n';
			indegree[next_node]--;
			if (!indegree[next_node])
				q.push(next_node);
		}
	}
	return result;
}

int main()
{
	int n, m, x, y, k;
	cin >> n >> m;
	vector<int> indegree(n + 1, 0);
	vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>(0));
	vector<bool> basic(n+1, true);
	while (m--)
	{
		cin >> x >> y >> k;
		indegree[y]++;
		graph[x].push_back({ y, k });
		basic[x] = false;
	}
	vector<vector<int>> result = topologicalSort(n, indegree, graph);
	for (int i = 1; i < n; i++)
	{
		if(basic[i] == true)
			cout << i << " " << result[n][i] << '\n';
	}
		
}