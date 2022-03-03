#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<int> base;

int moveBase(int num)
{
	int inning_score = 0;
	// 3루부터 주자 이동
	for (int i = 2; i >= 0; i--)
	{
		if (base[i] == 1)
		{
			if (i + num >= 3)
				inning_score++;
			else
				base[i + num] = 1;
			base[i] = 0;
		}
	}
	// 타자 본인
	base[num - 1] = 1;
	return inning_score;
}

int game(vector<int> order, int n)
{
	order.insert(order.begin() + 3, 0);
	int game_score = 0, cnt, player = 0;
	for(int i=0; i<n; i++)
	{
		cnt = 0;
		base = vector<int>(3, 0);
		while (cnt < 3)
		{
			switch (v[i][order[(player++)%9]])
			{
			case 0:
				cnt++;
				break;
			case 1:
				game_score += moveBase(1);
				break;
			case 2:
				game_score += moveBase(2);
				break;
			case 3:
				game_score += moveBase(3);
				break;
			case 4:
				game_score += 1 + base[0] + base[1] + base[2];
				base[0] = 0;
				base[1] = 0;
				base[2] = 0;
				break;
			}
		}
	}
	return game_score;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	// 입력
	int n;
	cin >> n;
	v = vector<vector<int>>(n, vector<int>(9, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 9; j++)
			cin >> v[i][j];
	int score = 0;
	vector<int> order;
	for (int i = 1; i <= 8; i++)
		order.push_back(i);
	// 연산
	while (next_permutation(order.begin(), order.end()))
		score = max(score, game(order, n));
	// 출력
	cout << score << '\n';
	return 0;
}