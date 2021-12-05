#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<double, double> ci;
typedef tuple<double, int, int> tp;

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
		return false;
	if (parent[xp] < parent[yp]) {
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else { 
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
	return true;
}

double kruskal(int v, priority_queue<tp, vector<tp>, greater<>>& pq) {
	int cnt = 0;
	double sum = 0;

	while (cnt < v - 1 && !pq.empty()) { 
		double weight = get<0>(pq.top());
		int x = get<1>(pq.top());
		int y = get<2>(pq.top());
		pq.pop();

		if (unionInput(x, y)) { // 유니온 했다면
			cnt++;
			sum += weight;
		}
	}
	return sum;
}

int main()
{
	int n, m, a, b;
	priority_queue<tp, vector<tp>, greater<>> pq;

	// 입력
	cin >> n >> m;
	parent.assign(n + 1, -1);
	vector<ci> gods(n + 1);
	// 좌표
	for (int i = 1; i < n + 1; i++)
		cin >> gods[i].first >> gods[i].second;
	// 이미 연결된 통로
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		unionInput(a, b);
	}
	// 연산
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j < n + 1; j++) {
			double xd = gods[i].first - gods[j].first;
			double yd = gods[i].second - gods[j].second;
			pq.push({ sqrt(xd * xd + yd * yd), i, j });
		}
	}
	// 연산 & 출력
	cout << fixed;
	cout.precision(2);
	cout << kruskal(n, pq);
}
