#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, float> tree;

int main()
{
	string input;
	int cnt = 0;
	while (getline(cin, input))
	{
		tree[input]++;
		cnt++;
	}
	cout << fixed;
	cout.precision(4);
	for (auto iter = tree.begin(); iter != tree.end(); iter++)
		cout << iter->first << ' ' << (iter->second/cnt)*100 << '\n';	
}