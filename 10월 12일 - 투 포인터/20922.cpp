#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, K, max_length = 0, cnt = 0;
	// 입력
	cin >> N >> K;
	vector<int> num(100001, 0);
	vector<int> v(N, 0);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	// 연산
	int left = 0, right = 0;
	while (right < N)
	{
		num[v[right]]++;
		// 같은 원소가 K개 초과 왼쪽 포인터 이동
		if (num[v[right]] == K+1)
		{
			while (v[left] != v[right])
			{
				num[v[left]]--;
				left++;
			}
			num[v[left]]--;
			left++;
		}
		max_length = max(max_length, right - left + 1);
		// 오른쪽 포인터 이동
		right++;
	}
	// 출력
	cout << max_length << '\n';
	return 0;
}