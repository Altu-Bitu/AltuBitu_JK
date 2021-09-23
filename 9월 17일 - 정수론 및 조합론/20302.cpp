#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 100000;

// 에라토스테네스의 체를 이용해서 소인수 구하기
vector<int> isPrime() {
	vector<int> prime(SIZE + 1, 0);
	for (int i = 2; i <= SIZE; i++)
		prime[i] = i;

	for (int i = 2; i <= sqrt(SIZE); i++) {
		if (prime[i] == i) {
			for (int j = i * i; j <= SIZE; j += i) {
				if (prime[j] == j) {
					prime[j] = i;
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

	// 0을 곱했는데 유리수로 판단하는 경우까지 생각해야 함
	// 0은 소인수분해가 되지 않기 때문에 저장하지 X
	int n, flag = 0, num, zero=0; char oper;

	// 소인수들을 저장하는 배열
	// factors[0]은 분자의 소인수
	// factors[1]은 분모의 소인수
	vector<vector<int>> factors(2, vector<int>(SIZE,0));

	// 에라토스테네스의 체
	vector<int> prime = isPrime();

	cin >> n;
	// 첫 숫자 입력
	cin >> num; num = abs(num);
	if (num == 0)
		zero = 1;
	// 소인수분해 후 factors[0]에 저장
	while (num > 1) { 
		factors[flag][prime[num]]++;
		//cout << prime[num] << '\n';
		num = num / prime[num];
	}
	// 나머지 숫자 입력
	for (int i = 1; i < n; i++)
	{
		cin >> oper >> num;
		num = abs(num);
		if (num == 0)
			zero = 1;
		if (oper == '*') // factors[0]에 저장
			flag = 0;
		else // factors[1]에 저장
			flag = 1;
		// 소인수분해
		while (num > 1) {
			factors[flag][prime[num]]++;
			//cout << prime[num] << '\n';
			num = num / prime[num];
		}
	}
	// 결과가 정수인지 유리수인지 판단
	for (int i = 2; i < SIZE; i++) {
		if (zero == 0 && factors[0][i] < factors[1][i])
		{
			cout << "toothpaste";
			return 0;
		}	
	}
	cout << "mint chocolate";
	return 0;
}