#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countColumn(vector<vector<char>> candy, int n)
{
	int max_candy = 0;
	char color;
	for (int i = 0; i < n; i++)
	{
		int tmp = 1;
		color = candy[i][0];
		for (int j = 1; j < n; j++)
		{
			if (color == candy[i][j])
				tmp++;
			else
			{
				tmp = 1;
				color = candy[i][j];
			}
			max_candy = max(max_candy, tmp);
		}
	}
	return max_candy;
}

int countRow(vector<vector<char>> candy, int n)
{
	int max_candy = 0;
	char color;
	for (int i = 0; i < n; i++)
	{
		int tmp = 1;
		color = candy[0][i];
		for (int j = 1; j < n; j++)
		{
			if (color == candy[j][i])
				tmp++;
			else
			{
				tmp = 1;
				color = candy[j][i];
			}
			max_candy = max(max_candy, tmp);
		}
	}
	return max_candy;
}

int main()
{
	// 입력
	int n, max_candy = 0;
	cin >> n;
	vector<vector<char>> candy(n, vector<char>(n, ' '));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> candy[i][j];
	// 연산
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (candy[i][j] != candy[i][j + 1]) // 행
			{
				swap(candy[i][j], candy[i][j + 1]);
				max_candy = max(countColumn(candy, n), max_candy);
				max_candy = max(countRow(candy, n), max_candy);
				swap(candy[i][j], candy[i][j + 1]);
			}
			if (candy[j][i] != candy[j + 1][i]) // 열
			{
				swap(candy[j][i], candy[j + 1][i]);
				max_candy = max(countColumn(candy, n), max_candy);
				max_candy = max(countRow(candy, n), max_candy);
				swap(candy[j][i], candy[j + 1][i]);
			}
		}
	}
	// 출력
	cout << max_candy << '\n';
}