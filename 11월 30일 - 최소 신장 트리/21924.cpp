#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;
typedef tuple<long long, int, int> tp;

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

long long kruskal(int v, priority_queue<tp, vector<tp>, greater<>>& pq)
{
	int cnt = 0;
	long long sum = 0;

	while (cnt < v - 1 && !pq.empty()) { // 사용한 간선의 수가 v - 1보다 작을 동안
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
	int n, m, a, b;
	long long c, total = 0;
	priority_queue<tp, vector<tp>, greater<>> pq;

	// 입력
	cin >> n >> m;
	parent.assign(n + 1, -1);
	while (m--) {
		cin >> a >> b >> c;
		total += c;
		pq.push({ c, a, b });
	}

	// 연산 & 출력
	long long ans = total - kruskal(n, pq);
	// 모든 노드를 연결할 수 없는 경우
	for (int i = 2; i <= n; i++)
	{
		if (findParent(1) != findParent(i))
		{
			ans = -1;
			break;
		}
	}
	cout << ans << '\n';
}