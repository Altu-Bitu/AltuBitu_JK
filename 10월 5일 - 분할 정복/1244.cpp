#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int n, stu;
	// 입력
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cin >> stu;
	vector<pair<int, int>> s(stu, {0,0});
	for (int i = 0; i < stu; i++)
		cin >> s[i].first >> s[i].second;
	// 연산
	for(int i=0; i<stu; i++)
	{		
		if (s[i].first == 1) // 남자
		{
			for(int j = 0; j < n; j++)
			{
				if ((j + 1) % s[i].second == 0)
					v[j] = 1 - v[j];
			}
		}
		else // 여자
		{
			v[s[i].second - 1] = 1 - v[s[i].second - 1];
			int j = s[i].second <= n / 2 ? s[i].second - 1 : n - s[i].second;
			for(int k=1; k<=j; k++)
			{
				if (v[s[i].second - 1 - k] == v[s[i].second - 1 + k])
				{
					v[s[i].second - 1 - k] = 1 - v[s[i].second - 1 - k];
					v[s[i].second - 1 + k] = 1 - v[s[i].second - 1 + k];
				}
				else break;
			}
		}
	}
	// 출력
	for (int i = 0; i < n; i++)
	{
		if (i != 0 && i % 20 == 0)
			cout << '\n';
		cout << v[i] << ' ';
	}
}