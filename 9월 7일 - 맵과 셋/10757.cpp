#include <iostream>
#include <string>

using namespace std;

string a, b, ans;

void sumBigNum(string a, string b)
{
	int digit = 0;
	int tmp = 0;
	while (a.size() > 0 && b.size() > 0)
	{
		digit = a.back() - '0' + b.back() - '0' + tmp; 
		tmp = digit / 10;
		digit %= 10;
		ans.push_back(digit + '0'); 
		a.pop_back();
		b.pop_back();
	}
	if (a.size() < b.size())
		swap(a, b);
	while (a.size() > 0 || tmp == 1)
	{
		if (a.size() > 0)
			digit = a.back() - '0' + tmp;
		else
			digit = tmp;
		tmp = digit / 10;
		digit %= 10;
		ans.push_back(digit + '0');
		if (a.size() > 0)
			a.pop_back();
	}
}

int main()
{
	cin >> a >> b;
	sumBigNum(a, b);
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i];
}