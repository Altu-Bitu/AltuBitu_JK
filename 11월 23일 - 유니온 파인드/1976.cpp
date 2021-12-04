#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findParent(int node) {
	if (parent[node] < 0)
		return node;
	return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp)
		return;
	if (parent[xp] < parent[yp]) {
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
}

int main()
{
	int n, m, input;
	cin >> n >> m;
	parent.assign(n + 1, -1);
	vector<int> path(m, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> input;
			if (input == 1)
				unionInput(i+1, j+1);
		}
	}
	for (int i = 0; i < m; i++)
		cin >> path[i];
	bool isPath = true;
	for (int i = 0; i < m; i++)
	{
		if (findParent(path[0]) != findParent(path[i]))
			isPath = false;
	}
	if (isPath)
		cout << "YES\n";
	else
		cout << "NO\n";
}