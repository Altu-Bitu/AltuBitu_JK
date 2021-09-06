#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char star[400][400];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= 4 * n - 4; i++)
	{
		for (int j = 0; j <= 4 * n - 4; j++)
		{
			star[i][j] = ' ';
		}
	}
	for (int i = 0; i <= 4*n-4; i += 2)
	{
		int cnt;
		if (i <= 2 * n - 2)
		{
			cnt = i;
			while (4 * n - 4 - cnt >= i)
			{
				star[i][cnt] = '*';
				cnt++;
			}
		}
		else
		{
			cnt = 4 * n - 4 - i;
			while (cnt <= i)
			{
				star[i][cnt] = '*';
				cnt++;
			}
		}
	}
	for (int i = 0; i <= 4 * n - 4; i += 2)
	{
		int cnt;
		if (i <= 2 * n - 2)
		{
			cnt = i;
			while (4 * n - 4 - cnt >= i)
			{
				star[cnt][i] = '*';
				cnt++;
			}
		}
		else
		{
			cnt = 4 * n - 4 - i;
			while (cnt <= i)
			{
				star[cnt][i] = '*';
				cnt++;
			}
		}
	}
	for (int i = 0; i <= 4 * n - 4; i++)
	{
		for (int j = 0; j <= 4 * n - 4; j++)
		{
			cout << star[i][j];
		}
		cout << '\n';
	}
}