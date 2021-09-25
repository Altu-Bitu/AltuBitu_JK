#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> v(3, vector<int>(n, 0));

int check(int num[])
{
	int val = 1;
	for (int j = 0; j < v[0].size(); j++)
	{
		int s_cnt = 0, b_cnt = 0;
		int guess_num[3];
		guess_num[0] = v[0][j] / 100; guess_num[1] = (v[0][j]/10)%10; guess_num[2] = v[0][j] % 10;
		for (int k = 0; k < 3; k++)
		{
			for (int p = 0; p < 3; p++)
			{
				if (num[k] == guess_num[p] && k == p)
					s_cnt++;
				else if (num[k] == guess_num[p])
					b_cnt++;
			}
		}
		if (s_cnt != v[1][j] || b_cnt != v[2][j])
			val = 0;
	}
	return val;
}

int main()
{
	int input, s, b, total_cnt = 0;
	cin >> n;
	while (n--)
	{
		cin >> input >> s >> b;
		v[0].push_back(input);
		v[1].push_back(s);
		v[2].push_back(b);
	}
	for (int i = 111; i <= 999; i++)
	{
		// 각 자리의 수 계산
		int num[3];
		num[0] = i / 100; num[1] = (i/10)%10; num[2] = i % 10;
		// 숫자에 0이 들어갈 때
		if (num[1] == 0 || num[2] == 0)
			continue;
		// 중복되는 숫자 있을 때
		if (num[0] == num[1] || num[1] == num[2] || num[0] == num[2])
			continue;
		// 조건에 맞는 수인지 체크
		total_cnt += check(num);
	}
	cout << total_cnt << '\n';
}