#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 1e6;

// 역추적
vector<int> back(int x, vector<int>& path) {
	vector<int> result(0); // 정답 경로
	while (x != -1) {
		result.push_back(x);
		x = path[x]; // 다음 정점
	}
	return result;
}

int bfs(int n, vector<int>& path) {
	vector<int> check(SIZE + 1, 0);
	queue<int> q;
	int ans = 0; // 최단 시간

	check[n] = 1;
	q.push(n); 
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == 1) { // 1 찾으면 탐색 종료
			ans = check[x] - 1;
			break;
		}
		int child;
		if (x % 3 == 0) // 3으로 나눈 나머지가 0
		{
			child = x / 3;
			if (child >= 0 && child <= SIZE && !check[child]) {
				check[child] = check[x] + 1;
				path[child] = x;  // 경로 저장
				q.push(child);
			}
		}
		if (x % 2 == 0) // 2으로 나눈 나머지가 0
		{
			child = x / 2;
			if (child >= 0 && child <= SIZE && !check[child]) {
				check[child] = check[x] + 1;
				path[child] = x;  // 경로 저장
				q.push(child);
			}
		}
		child = x -1;
		if (child >= 0 && child <= SIZE && !check[child]) {
			check[child] = check[x] + 1;
			path[child] = x;  // 경로 저장
			q.push(child);
		}
	}
	return ans;
}

int main()
{
	vector<int> path(SIZE + 1, -1); // 경로 저장 벡터
	int n;

	// 입력
	cin >> n;

	// 연산
	int ans = bfs(n, path);
	vector<int> result = back(1, path);

	// 출력
	cout << ans << '\n';
	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i] << ' ';
	return 0;
}