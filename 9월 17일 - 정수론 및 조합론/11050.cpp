#include <iostream>

using namespace std;

int factorial(int n)
{
	if (n <= 1)
		return 1;
	return n * factorial(n - 1);
}

int main()
{
	int n, k, nCk;
	// 입력
	cin >> n >> k;

	// Binomial
	nCk = factorial(n) / (factorial(k) * factorial(n - k));

	// 출력
	cout << nCk;
}
