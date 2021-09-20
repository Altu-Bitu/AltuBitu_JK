#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector <int> s;
	s.assign(20, 0);
	int M, n;
	string cmd;
	cin >> M; cout.tie(NULL);
	while (M--)
	{
		cin >> cmd;
		if (cmd == "add")
		{
			cin >> n;
			s[n - 1] = 1;
		}
		if (cmd == "remove")
		{
			cin >> n;
			s[n - 1] = 0;
		}
		if (cmd == "check")
		{
			cin >> n;
			if (s[n-1] == 1)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		if (cmd == "toggle")
		{
			cin >> n;
			if (s[n - 1] == 1)
				s[n - 1] = 0;
			else
				s[n - 1] = 1;
		}
		if (cmd == "all")
		{
			for (int i = 0; i < 20; i++)
				s[i] = 1;
		}
		if (cmd == "empty")
		{
			for (int i = 0; i < 20; i++)
				s[i] = 0;
		}
	}
	return 0;
}