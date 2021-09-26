#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, max_money = 0;
vector<pair<int, int>> v;

void resign(int day, int money)
{
	// 퇴사하는 날
	if (day == n)
		max(max_money, money)
	if (day >= n)
		return;
	// 하루 건너뜀
	resign(day + 1, money);
	// 상담
	resign(day + v[day].first, money + v[day].second);
}

int main()
{
	cin >> n;
	v.assign(n, {});
	// 입력
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	// 연산
	resign(0, 0);
	cout << max_money << '\n';
	return 0;
}
