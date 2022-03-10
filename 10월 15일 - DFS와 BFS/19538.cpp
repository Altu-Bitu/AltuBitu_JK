#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> nt;

vector<vector<int>> adj_list; // 주변인과의 관계
vector<int> rumor; // 루머를 믿게 된 시간
vector<int> trust; // 루머를 믿는 주변인의 인원수
queue<nt> q;
queue<nt> tq; // 동시간대 처리하는

int timer = 0;

void bfs(int n, int m)
{
	while (!q.empty())
	{
		int node = q.front().first; // 본인
		int time = q.front().second; // 루머를 믿게 된 시간
		// 큐의 다음 node의 시간
		if (time != timer)
		{
			timer = time;
			while (!tq.empty())
			{
				rumor[tq.front().first] = tq.front().second;
				tq.pop();
			}
		}
		q.pop();
		int ac = adj_list[node].size(); // 주변인
		for (int i = 0; i < ac; i++)
		{
			tq.push(nt(node, time));
			if (rumor[adj_list[node][i]] == -1)
			{
				trust[adj_list[node][i]]--;
				if (trust[adj_list[node][i]] == 0)
				{
					q.push(nt(adj_list[node][i], time + 1));
					// tq.push(nt(adj_list[node][i], time + 1));
				}
			}
		}
	}
	while (!tq.empty())
	{
		rumor[tq.front().first] = tq.front().second;
		tq.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, node, m;
	// 입력
	cin >> n;
	adj_list.assign(n + 1, vector<int>());
	trust.assign(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		while (true)
		{
			cin >> node;
			if (node == 0)
				break;
			adj_list[i].push_back(node);
		}
		trust[i] = round((float)adj_list[i].size() / 2);
	}
	cin >> m;
	rumor.assign(n + 1, -1);
	for (int i = 0; i < m; i++)
	{
		cin >> node;
		rumor[node] = 0;
		q.push(nt(node, 0));
	}
	// 연산
	bfs(n, m);
	// 출력
	for (int i = 1; i <= n; i++)
		cout << rumor[i] << ' ';
}