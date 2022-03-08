#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_sushi = 0;

int main()
{
	int N, d, k, c, cnt = 0;
	// 입력
	cin >> N >> d >> k >> c;
	vector<int> v(N, 0);
	vector<int> sushi(d+1, 0);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	// 연산
	// 초기화
	for (int i = 0; i < k; i++)
	{
		sushi[v[i]]++;
		cnt += (sushi[v[i]] == 1);
	}
	int left = 0, right = k-1;
	while (left != N - 1)
	{
		max_sushi = max(max_sushi, cnt + (sushi[c] == 0));
		// 왼쪽 포인터
		cnt -= (sushi[v[left]] == 1);
		sushi[v[left++]]--;
		// 오른쪽 포인터
		right = (right + 1) % N;
		sushi[v[right]]++;
		cnt += (sushi[v[right]] == 1);
	}
	// 출력
	cout << max_sushi<<'\n';
}