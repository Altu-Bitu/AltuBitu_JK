#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursively find GCD
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	// 입출력 속도
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t, n;
	cin >> t;
	while (t--)
	{
		// 입력
		cin >> n;
		vector<int> num;
		// 합이므로 long long으로 선언
		long long sum = 0;
		num.assign(n, 0);
		for (int i = 0; i < n; i++)
			cin >> num[i];
		// 가능한 모든 쌍의 개수 n*(n-1)/2
		// 모든 GCD 의 합
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				sum += gcd(max(num[i], num[j]), min(num[i], num[j]));
		cout << sum << '\n';
	}
	return 0;
}