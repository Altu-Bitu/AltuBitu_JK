#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> tree;

int main()
{
	// 입출력 속도 향상 필요
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b, q, t, k;
	cin >> n;
	tree.assign(n + 1, vector<int> {});
	// 연속된 정점 (작은 수 -> 큰수)
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	cin >> q;
	while (q--)
	{
		cin >> t >> k;
		// t == 1 단절점
		if (t == 1)
		{
			if (tree[k].size() != 1) // 연결된 정점이 2개 이상일 때
				cout << "yes\n";
			else
				cout << "no\n";
		}
		// t == 2 단절선
		// 단절선을 제거하면 무조건 그래프가 2개 이상으로 나뉨
		else if (t == 2)
			cout << "yes\n";
	}
}