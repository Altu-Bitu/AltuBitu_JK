#include <iostream>
#include <set>

using namespace std;

int main()
{
	int n, m, ans = 0;
	set <string> s;
	string input;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		s.insert(input);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		auto iter = s.find(input);
		if (iter != s.end())
			ans++;
	}
	cout << ans;
}