#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct coordinate {
	int x, y;
};

bool cmp(const coordinate& c1, const coordinate& c2)
{
	if (c1.y != c2.y)
		return c1.y < c2.y;
	return c1.x < c2.x;
}

int main()
{
	int n;
	cin >> n;
	vector<coordinate> my_axis;
	my_axis.assign(n, {});
	for (int i = 0; i < n; i++)
		cin >> my_axis[i].x >> my_axis[i].y;
	sort(my_axis.begin(), my_axis.end(), cmp);
	for (int i = 0; i < my_axis.size(); i++)
		cout << my_axis[i].x << ' ' << my_axis[i].y << '\n';

}