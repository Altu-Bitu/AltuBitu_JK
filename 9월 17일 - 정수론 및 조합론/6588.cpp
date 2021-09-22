#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int SIZE = 1000000;

// 소수 경로 저장해서 리턴하는 함수
vector<int> isPrime() {
	vector<int> prime(SIZE + 1, 0);
	// 먼저 모든 수를 소수라 가정하고, i번째 인덱스에 i값 저장
	for (int i = 2; i <= SIZE; i++)
		prime[i] = i;

	// 소수 판별
	for (int i = 2; i <= sqrt(SIZE); i++) {
		if (prime[i] == i) { //소수라면
			for (int j = i * i; j <= SIZE; j += i) { // 배수에 소수(i) 저장
				if (prime[j] == j) { // 저장된 소수가 없을 경우만
					prime[j] = i; // 소수 저장
				}
			}
		}
	}

	return prime;
}

int main()
{
	// 입출력 속도
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> prime = isPrime();
	while (n)
	{
		for (int i = 3; i <= n / 2; i += 2)
		{
			if (prime[i] == i && prime[n-i] == n-i)
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
