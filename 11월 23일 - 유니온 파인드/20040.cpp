#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findParent(int node) {
	if (parent[node] < 0)
		return node;
	return parent[node] = findParent(parent[node]); 
}

bool unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp)
		return true;
	if (parent[xp] < parent[yp]) {
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
	return false;
}

int main()
{
	int n, m, a, b, end = 0;
	cin >> n >> m;
	parent.assign(n + 1, -1);
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		if (unionInput(a + 1, b + 1))
		{
			end = i;
			break;
		}
	}
	cout << end << '\n';
}
