#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
vector<vector<int>> v(3, vector<int>(n, 0));

bool check(string num)
{
	bool val = true;
	for (int j = 0; j < v[0].size(); j++)
	{
		int s_cnt = 0, b_cnt = 0;
		string guess_num = to_string(v[0][j]);
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
			val = false;
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
		string num = to_string(i);
		// 숫자에 0이 들어갈 때
		if (num[1] == '0' || num[2] == '0')
			continue;
		// 중복되는 숫자 있을 때
		if (num[0] == num[1] || num[1] == num[2] || num[0] == num[2])
			continue;
		// 조건에 맞는 수인지 체크
		total_cnt += check(num);
	}
	cout << total_cnt << '\n';
}
