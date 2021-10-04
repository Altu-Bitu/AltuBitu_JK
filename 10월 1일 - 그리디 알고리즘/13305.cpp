#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// 입력
	int n;
	long long ans = 0, min_price = 1000000000;	
	cin >> n;
	vector<int> dist(n - 1, 0);
	vector<long long> city(n, 0);	
	for (int i = 0; i < n - 1; i++)
		cin >> dist[i];
	for (int i = 0; i < n; i++)
		cin >> city[i];
	// 연산
	// min 함수는 long long과 int를 비교할 수 없으므로
	// 둘다 long long으로
	// 아니면 ans에 더할 때 long long으로 형변환해도 된다.
	for (int i = 0; i < n-1; i++)
	{
		min_price = min(min_price, city[i]);
		ans += min_price * dist[i];
	}
	cout << ans << '\n';
	return 0;
}