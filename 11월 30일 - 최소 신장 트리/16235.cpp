#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
typedef vector<int> tree; // 나이, 생존

vector<vector<int>> nutrition;
vector<vector<tree>> alive;
vector<vector<tree>> dead;
vector<vector<int>> A;
int n;

int dr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dc[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void spring()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (alive[i][j].size() > 0)
			{
				sort(alive[i][j].begin(), alive[i][j].end());
				tree tmp;
				for (int k =0; k < alive[i][j].size(); k++)
				{
					if (nutrition[i][j] >= alive[i][j][k])
					{
						nutrition[i][j] -= alive[i][j][k];
						tmp.push_back(alive[i][j][k] + 1);
					}
					else
						dead[i][j].push_back(alive[i][j][k]);
				}
				alive[i][j].clear();
				alive[i][j] = tmp;
			}
		}
	}
}

void summer()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < dead[i][j].size(); k++)
				nutrition[i][j] += dead[i][j][k] / 2;
			dead[i][j].clear();
		}
	}
}

void fall()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < alive[i][j].size(); k++)
			{
				if (alive[i][j][k] % 5 == 0)
				{
					for (int d = 0; d < 8; d++)
					{
						int x = i + dr[d];
						int y = j + dc[d];
						if (x >= 0 && x < n && y >= 0 && y < n)
							alive[x][y].push_back(1);
					}
				}
			}
		}
	}
}

void winter()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			nutrition[i][j] += A[i][j];
	}
}

int countTree()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cnt += alive[i][j].size();
	return cnt;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int m, k, x, y, z;
	// 입력
	cin >> n >> m >> k;
	nutrition.assign(n, vector<int>(n, 5));
	alive.assign(n, vector<tree>(n));
	dead.assign(n, vector<tree>(n));
	A.assign(n, vector<int>(n, 5));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> z;
		alive[x - 1][y - 1].push_back(z);
	}
	// 연산
	while (k--)
	{
		spring();
		summer();
		fall();
		winter();
	}
	// 출력
	cout << countTree() << '\n';
}