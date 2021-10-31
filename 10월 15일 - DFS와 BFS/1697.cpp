#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> lt;

int bfs(int n, int k)
{
	queue<lt> q;
	q.push(lt(n, 0));
	// 방문한 곳 체크, 이미 간 곳 나중에 갈 필요 없으니 공유 가능
	// 체크 안하면 메모리 초과
	vector<int> visited(100001, 0);
	while (!q.empty())
	{
		int cl = q.front().first;
		int ct = q.front().second;
		visited[cl] = 1;
		q.pop();
		// 수빈 == 동생
		if (cl == k)
			return ct;
		if (cl + 1 <= 100000 && !visited[cl + 1])
		{
			q.push(lt(cl + 1, ct + 1));
			visited[cl + 1] = 1;
		}	
		if (cl * 2 <= 100000 && !visited[cl * 2])
		{
			q.push(lt(cl * 2, ct + 1));
			visited[cl * 2] = 1;
		}
		if (cl - 1 >= 0 && !visited[cl - 1])
		{
			q.push(lt(cl - 1, ct + 1));
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