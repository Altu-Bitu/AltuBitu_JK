#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int r, b, area, l, w;
	cin >> r >> b;
	area = r + b;
	for (int i = 1; i <= area; i++)
	{
		if (area % i == 0)
		{
			l = area / i;
			w = i;
			if (r == (2 * (l + w) - 4))
				break;
		}
	}
	cout << l << ' ' << w << '\n';
}