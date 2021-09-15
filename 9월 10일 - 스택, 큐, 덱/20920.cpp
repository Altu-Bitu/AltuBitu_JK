#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int>& pr1, pair<string, int>& pr2)
{
	if (pr1.second != pr2.second)
		return pr1.second > pr2.second;
	if (pr1.first.size() != pr2.first.size())
		return pr1.first.size() > pr2.first.size();
	return pr1.first < pr2.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	string input;
	map <string, int> mp;
	vector<pair<string, int>> pr;
	while (n--)
	{
		cin >> input;
		if(input.size() >= m)
			mp[input]++;
	}
	for (auto iter = mp.begin(); iter != mp.end(); iter++)
		pr.push_back(*iter);
	sort(pr.begin(), pr.end(), cmp);
	for (auto iter = pr.begin(); iter != pr.end(); iter++)
		cout << iter->first << '\n';
}