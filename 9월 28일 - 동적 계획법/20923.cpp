#include <iostream>
#include <deque>

using namespace std;

deque<int> d[2], g[2];
int turn = 0;

void round()
{
	// SUYEON
	if (!g[0].empty() && !g[1].empty() && (g[0].front() + g[1].front() == 5))
	{
		while (!g[0].empty())
		{
			d[1].push_back(g[0].back());
			g[0].pop_back();
		}
		while (!g[1].empty())
		{
			d[1].push_back(g[1].back());
			g[1].pop_back();
		}
	}
	// DODO
	else if ((!g[0].empty() && g[0].front() == 5) || (!g[1].empty() && g[1].front() == 5))
	{
		while (!g[1].empty())
		{
			d[0].push_back(g[1].back());
			g[1].pop_back();
		}
		while (!g[0].empty())
		{
			d[0].push_back(g[0].back());
			g[0].pop_back();
		}
	}
}

string win()
{
	if (d[0].size() > d[1].size())
		return "do";
	else if (d[0].size() < d[1].size())
		return "su";
	return "dosu";
}

string game(int m)
{
	while (m--)
	{
		g[turn].push_front(d[turn].front());
		d[turn].pop_front();
		if (d[turn].empty())
			break;
		round();
		turn = (turn == 1) ? 0 : 1;
	}
	return win();
}

int main()
{
	int n, m, input1, input2;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> input1 >> input2;
		d[0].push_front(input1);
		d[1].push_front(input2);
	}
	cout << game(m)<<'\n';
}