#include <iostream>
#include <vector>
#include <queue>

#define MAX 100000

using namespace std;

typedef pair<int, int> lt;

int bfs(int n, int k)
{
	// 가중치(0, 1) 있기 때문에 0부터 처리 (min heap)
	priority_queue<lt, vector<lt>, greater<>> pq;
	pq.push(lt(0, n)); // 시간을 기준으로 우선 순위 큐 구현
	// 방문한 곳 체크, 이미 간 곳 나중에 갈 필요 없으니 공유 가능
	// 체크 안하면 메모리 초과
	vector<int> visited(MAX + 1, 0);
	while (!pq.empty())
	{
		int ct = pq.top().first;
		int cl = pq.top().second;
		//visited[cl] = 1;
		pq.pop();
		// 수빈 == 동생
		if (cl == k)
			return ct;
		// 가중치 작은 순간이동부터 처리 (순서 바꾸면 틀림)
		if (cl * 2 <= MAX && !visited[cl * 2])
		{
			pq.push(lt(ct, cl * 2));
			visited[cl * 2] = 1;
		}
		if (cl + 1 <= MAX && !visited[cl + 1])
		{
			pq.push(lt(ct + 1, cl + 1));
			visited[cl + 1] = 1;
		}
		if (cl - 1 >= 0 && !visited[cl - 1])
		{
			pq.push(lt(ct + 1, cl - 1));
			visited[cl - 1] = 1;
		}
	}
}

int main()
{
	int n, k;
	// 입력
	cin >> n >> k;
	// 연산 & 출력	
	cout << bfs(n, k) << '\n';
}