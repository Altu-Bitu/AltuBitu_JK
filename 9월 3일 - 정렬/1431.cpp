#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string &s1, string &s2)
{
	if (s1.size() != s2.size())
		return s1.size() < s2.size();
	int s1_sum = 0, s2_sum=0; 
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] >= '0' && s1[i] <= '9')
			s1_sum += (int)(s1[i] - '0');
		if (s2[i] >= '0' && s2[i] <= '9')
			s2_sum += (int)(s2[i] - '0');
	}
	if (s1_sum != s2_sum)
		return s1_sum < s2_sum;
	int idx = 0;
	while (s1[idx] == s2[idx])
		idx++;
	return s1[idx] < s2[idx];
}

int main()
{
	int n;
	cin >> n;
	vector<string> guitar;
	guitar.assign(n, "");
	for (int i = 0; i < n; i++)
		cin >> guitar[i];
	sort(guitar.begin(), guitar.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << guitar[i]<<'\n';
}