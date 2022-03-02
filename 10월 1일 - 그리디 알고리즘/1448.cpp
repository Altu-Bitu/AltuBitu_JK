#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	// 입력
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	// 내림차순 정렬
	sort(v.begin(), v.end(), greater<>());
	// n-3, n-2, n-1
	int ans = 0, p = 0;
	// 연산
	while (p <= n - 3)
	{
		if (v[p] < v[p + 1] + v[p + 2])
		{
			ans = v[p] + v[p + 1] + v[p + 2];
			break;
		}
		p++;
	}
	if (ans == 0)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
}