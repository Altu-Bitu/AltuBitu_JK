#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, vector<int>> tree;
vector<int> nodes;
vector<bool> visited;

int dfs(int root)
{
	for (int i = 0; i < tree[root].size(); i++)
	{
		if (!visited[tree[root][i]])
		{
			visited[tree[root][i]] = true;
			nodes[root] += dfs(tree[root][i]);
		}
	}
	return nodes[root];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, r, q, u, v;
	cin >> n >> r >> q;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	nodes.assign(n + 1, 1);
	visited.assign(n + 1, false);
	visited[r] = true;
	dfs(r);
	while (q--)
	{
		cin >> u;
		cout << nodes[u] << '\n';
	}
}