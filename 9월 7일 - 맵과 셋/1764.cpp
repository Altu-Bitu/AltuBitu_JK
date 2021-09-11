#include <iostream>
#include <set>

using namespace std;

set<string> s1, s2, s3;

void intersection(set<string> s1, set<string> s2, set<string> s3)
{
	for (auto iter1 = s1.begin(); iter1 != s1.end(); iter1++)
	{
		auto iter2 = s2.find(*iter1);
		if (iter2!=s2.end())
			s3.insert(*iter1);
	}
	cout << s3.size()<<'\n';
	for (auto iter3 = s3.begin(); iter3 != s3.end(); iter3++)
		cout << *iter3<<'\n';
}

int main()
{
	int n, m;
	cin >> n >> m;
	string input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		s1.insert(input);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		s2.insert(input);
	}
	intersection(s1, s2, s3);
}