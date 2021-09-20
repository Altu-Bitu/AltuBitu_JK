#include <iostream>
#include <vector>
#include <map>

using namespace std;
// s(i): sum of a[0]~a[i]
// s(j) - s(i - 1) = k
// s(i - 1) = s(j) - k
vector<int> a;
vector<int> sum;
map<int, long long> m;

void prefix_sum(int n, int k)
{
	long long ans = 0;
	sum.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			sum[0] = a[0];
		else
			sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 0; i < n; i++)
	{
		// s(i - 1) = s(j) - k
		ans += m[sum[i] - k];
		// s(i - 1) = k
		if (sum[i] == k)
			ans++;
		m[sum[i]]++;
	}
	cout << ans;
}

int main()
{
	int n, k, input;
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		a.push_back(input);
	}
	prefix_sum(n, k);
}
