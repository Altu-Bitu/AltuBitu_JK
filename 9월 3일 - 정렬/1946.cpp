#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ranking
{
	int paper, interview;
};

bool cmp_paper(ranking& r1, ranking& r2)
{
	return r1.paper < r2.paper;
}

int main()
{
	int t, n;
	cin >> t;
	vector<int> newcomer;
	newcomer.assign(t, 0);
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		vector<ranking> trial;
		int max_paper = n, max_interview = n;
		trial.assign(n, {});
		for (int j = 0; j < n; j++)
			cin >> trial[j].paper >> trial[j].interview;
		sort(trial.begin(), trial.end(), cmp_paper);
		max_interview = trial[0].interview;
		for (int j = 0; j < n; j++)
		{
			if (trial[j].interview <= max_interview)
			{
				max_interview = trial[j].interview;
				newcomer[i]++;
			}	
		}
	}
	for (int i = 0; i < t; i++)
		cout << newcomer[i] << '\n';
}
