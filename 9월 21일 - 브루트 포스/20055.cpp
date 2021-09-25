#include <iostream>
#include <deque>

using namespace std;

int main()
{
	int n, k, input, stage = 0;
	cin >> n >> k;
	deque<pair<int, bool>> a;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> input;
		a.push_back(make_pair(input, false));
	}
	pair<int, bool> tmp;
	while (true)
	{
		stage++;

		// rotate the belt
		a.push_front(a.back());
		a.pop_back();
		a[n - 1].second = false;

		// move the robots (first come first move)
		// 가장 먼저 벨트에 올라간 로봇부터 + 벨트가 회전하는 방향으로 이동
		for (int i = n - 2; i >= 0; i--)
		{
			if (a[i].second == true && a[i + 1].second == false && a[i + 1].first >= 1)
			{
				a[i].second = false;
				a[i + 1].second = true;
				a[i + 1].first--;
			}
		}
		a[n - 1].second = false;

		// put a robot
		if (a[0].first != 0)
		{
			a[0].first--;
			a[0].second = true;
		}

		// durability check
		int cnt = 0;
		for (int i = 0; i < 2 * n; i++)
		{
			if (a[i].first == 0)
				cnt++;
			if (cnt >= k)
			{
				cout << stage << '\n';
				return 0;
			}
		}
	}
	return 0;
}