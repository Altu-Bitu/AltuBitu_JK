#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int direction[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} }; // 반시계

int n, m;
vector<pair<int, int>> cctv;
vector<vector<int>> space;
int min_blind_spot = 64;

// 사각지대 계산
int blindSpot(vector<vector<int>>& tmp)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tmp[i][j] == 0)
				cnt++;
		}
	}
	return cnt;
}

// CCTV로 감시할 수 있는 영역
vector<vector<int>> sense(int i, vector < vector<int>>& tmp, int dir)
{
	int next_r = cctv[i].first + direction[dir % 4][0];
	int next_c = cctv[i].second + direction[dir % 4][1];
	while (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m)
	{
		if (tmp[next_r][next_c] == 6)
			break;
		else if (tmp[next_r][next_c] == 0)
			tmp[next_r][next_c] = 7;
		next_r += direction[dir % 4][0];
		next_c += direction[dir % 4][1];
	}
	return tmp;
}

void setCCTV(int cnt, vector<vector<int>>& cnt_tmp)
{
	// 모든 CCTV에 대해서 감시 영역 다 표시 후
	if (cctv.size() == cnt)
	{
		min_blind_spot = min(min_blind_spot, blindSpot(cnt_tmp));
		/*
		cout << "----------------------" << '\n';
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << cnt_tmp[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << "----------------------" << '\n';
		*/
		return;
	}
	// 갱신 전 상태 저장 
	vector<vector<int>> prior = cnt_tmp;
	// CCTV 종류에 따라 감지영역 표시
	switch (space[cctv[cnt].first][cctv[cnt].second])
	{
	case 1: // 1번 CCTV
	{
		for (int i = 0; i < 4; i++)
		{
			cnt_tmp = sense(cnt, cnt_tmp, i);
			setCCTV(cnt + 1, cnt_tmp);
			cnt_tmp = prior;
		}

		break;
	}
	case 2: // 2번 CCTV
	{
		for (int i = 0; i < 2; i++)
		{
			cnt_tmp = sense(cnt, cnt_tmp, i);
			cnt_tmp = sense(cnt, cnt_tmp, i + 2);
			setCCTV(cnt + 1, cnt_tmp);
			cnt_tmp = prior;
		}
		break;
	}
	case 3: // 3번 CCTV
	{
		for (int i = 0; i < 4; i++)
		{
			cnt_tmp = sense(cnt, cnt_tmp, i);
			cnt_tmp = sense(cnt, cnt_tmp, i + 1);
			setCCTV(cnt + 1, cnt_tmp);
			cnt_tmp = prior;
		}
		break;
	}
	case 4: // 4번 CCTV
	{
		for (int i = 0; i < 4; i++)
		{
			cnt_tmp = sense(cnt, cnt_tmp, i);
			cnt_tmp = sense(cnt, cnt_tmp, i + 1);
			cnt_tmp = sense(cnt, cnt_tmp, i + 2);
			setCCTV(cnt + 1, cnt_tmp);
			cnt_tmp = prior;
		}
		break;
	}
	case 5: // 5번 CCTV
	{
		cnt_tmp = sense(cnt, cnt_tmp, 0);
		cnt_tmp = sense(cnt, cnt_tmp, 1);
		cnt_tmp = sense(cnt, cnt_tmp, 2);
		cnt_tmp = sense(cnt, cnt_tmp, 3);
		setCCTV(cnt + 1, cnt_tmp);
		cnt_tmp = prior;
		break;
	}
	}
}

int main()
{
	// 입력
	cin >> n >> m;
	space.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> space[i][j];
			if (space[i][j] != 0 && space[i][j] != 6)
				cctv.push_back(make_pair(i, j));
		}
	}
	vector<vector<int>> cnt_tmp = space;
	// 연산
	setCCTV(0, cnt_tmp);
	// 출력
	cout << min_blind_spot << '\n';
}