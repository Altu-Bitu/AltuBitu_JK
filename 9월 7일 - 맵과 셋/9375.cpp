#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int t, n;
	vector<int> ans;
	string input, type;
	cin >> t;
	ans.assign(t, 1);
	for (int j=0; j<t; j++)
	{
		cin >> n;
		map<string, int> clothes;
//		for (auto it = clothes.begin(); it != clothes.end(); it++)
//			it->second=0;
		for (int i = 0; i < n; i++)
		{
			cin >> input >> type;
			clothes[type]++;
		}
		for (auto it=clothes.begin(); it !=clothes.end(); it++)
			ans[j] *= (it->second + 1);
		ans[j]--;
	}
	for (int i = 0; i < t; i++)
		cout << ans[i]<<'\n';
}