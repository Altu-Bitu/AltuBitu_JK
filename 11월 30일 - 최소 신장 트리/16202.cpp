#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;
int findParent(int node) {
	if (parent[node] < 0)
		return node;
	return parent[node] = findParent(parent[node]);
}

bool unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp) // 같은 집합에 있다면 유니온 할 수 없음
		return false;
	if (parent[xp] < parent[yp]) { // 새로운 루트 xp
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else { // 새로운 루트 yp
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
	return true;
}

int kruskal(int v, priority_queue<tp, vector<tp>, greater<>>& pq)
{
	int cnt = 0;
	int sum = 0;

	while (cnt < v - 1) { // 사용한 간선의 수가 v - 1보다 작을 동안
		if (pq.empty())
			return -1;
		long long weight = get<0>(pq.top());
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
	int n, m, a, b, k;
	priority_queue<tp, vector<tp>, greater<>> pq;
	priority_queue<tp, vector<tp>, greater<>> tmp;

	// 입력
	cin >> n >> m >> k;
	parent.assign(n + 1, -1);
	for(int i=1; i<=m; i++)
	{
		cin >> a >> b;
		pq.push({ i, a, b });
	}

	// 연산 & 출력
	int finish = -1;
	for (int i = 0; i < k; i++)
	{
		tmp = pq;
		int ans = kruskal(n, pq);
		if (ans == -1)
		{
			finish = i;
			break;
		}
		else
			cout << ans << ' ';
		pq = tmp;
		pq.pop();
		parent.assign(n + 1, -1);
	}
	if (finish != -1)
	{
		for (int j = finish; j < k; j++)
			cout << 0 << ' ';
	}
	
}