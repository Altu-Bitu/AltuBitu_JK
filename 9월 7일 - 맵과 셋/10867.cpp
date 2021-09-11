#include <iostream>
#include <set>

using namespace std;

void print_set(set<int> s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
		cout << *it << ' ';
}

int main()
{
	int n, x;
	set<int> s;
	cin >> n;
	// i 필요 없으므로 for 대신 while
	while (n--) 
	{ 
		cin >> x;
		s.insert(x);
	}
	print_set(s);
}