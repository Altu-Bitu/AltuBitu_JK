#include <iostream>
#include <set>

using namespace std;

int main()
{
	int t, n, k;
	char cmd;
	cin >> t;
	while (t--)
	{
		cin >> n;
		multiset<int> s;
		while (n--)
		{
			cin >> cmd >> k;
			if (cmd == 'I')
				s.insert(k);
			else
			{
				if ((!s.empty()) && k == -1)
					s.erase(s.begin());
				else if (!s.empty())
				{
					auto iter = s.end();
					s.erase(--iter);
				}
			}
		}
		if (s.empty())
			cout << "EMPTY" << '\n';
		else
		{
			auto iter = s.end();
			cout << *(--iter) << ' ' << *s.begin() << '\n';
		}			
	}
	return 0;
}