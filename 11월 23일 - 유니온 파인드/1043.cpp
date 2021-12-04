#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

// Find 연산
int findParent(int node) {
	if (parent[node] < 0) 
		return node;
	return parent[node] = findParent(parent[node]); 
}

// Union 연산
void unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp) { 
		return;
	}
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
	int n, m, t, p, input, cnt = 0;
	// 입력
	cin >> n >> m >> t;
	vector<int> truth(t, 0);
	vector<vector<int>> party(m, vector<int>{});
	parent.assign(n + 1, -1);
	for (int i = 0; i < t; i++)
		cin >> truth[i];
	for (int i = 0; i < m; i++)
	{
		cin >> p;
		for (int j = 0; j < p; j++)
		{
			cin >> input;
			party[i].push_back(input);
			unionInput(party[i][0], party[i][j]);
		}	
	}
	// 연산
	for (int i = 0; i < m; i++)
	{
		// 진실을 아는 사람이 그룹에 한명이라도 있으면 
		// 파티에서 과장을 이야기 할 수 없음
		bool overstate = true;
		for (int j = 0; j < t; j++)
		{
			if (findParent(party[i][0]) == findParent(truth[j]))
				overstate = false;
		}
		if (overstate)
			cnt++;
	}
	// 출력
	cout << cnt << '\n';
}