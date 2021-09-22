#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

int main()
{
	// 입출력 속도
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	while (n)
	{
		for (int i = 3; i <= n/2; i+=2)
		{
			if (isPrime(i) && isPrime(n - i))
			{
				cout << n << " = " << i << " + " << n - i << '\n';
				break;
			}
			if (i > n / 2)
			{
				cout << "Goldbach's conjecture is wrong.";
				return 0;
			}
		}
		cin >> n;
	}
}