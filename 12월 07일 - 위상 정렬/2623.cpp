#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 위상정렬
vector<int> topologicalSort(int n, vector<int>& indegree, vector<vector<int>>& graph) {
	vector<int> result;
	queue<int> q;
	for (int i = 1; i <= n; i++) 
	{
		if (!indegree[i])
			q.push(i);
	}
	while (!q.empty()) 
	{
		int node = q.front();
		q.pop();

		result.push_back(node);
		for (int i = 0; i < graph[node].size(); i++) 
		{
			int next_node = graph[node][i];
			indegree[next_node]--;
			if (!indegree[next_node])
				q.push(next_node);
		}
	}
	return result;
}

int main()
{
	int n, m, num, a, b;
	cin >> n >> m;
	vector<int> indegree(n + 1, 0);
	vector<vector<int>> graph(n + 1, vector<int>(0));
	while (m--)
	{
		cin >> num;
		cin >> a;
		num -= 1;
		while (num--)
		{
			cin >> b;
			indegree[b]++;
			graph[a].push_back(b);
			a = b;
		}
	}
	vector<int> result = topologicalSort(n, indegree, graph);

	// 출력
	if (result.size() < n)
	{
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 0; i < n; i++)
		cout << result[i] << '\n';
}
