#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int LINE = 6;

int main()
{
	// 입력
	int N, P, L, note, cnt = 0;
	cin >> N >> P;

	stack <int> moves[LINE];
	for (int i = 0; i < N; i++)
	{
		cin >> L >> note;
		// 그 줄에 무언가 누르고 있을 때
		if(!moves[L - 1].empty())
		{
			// 누른 음의 프렛이 더 낮거나 같을 때
			if (moves[L - 1].top() >= note);
			{
				// 누른 음의 프렛이 더 낮을 때
				while (!moves[L - 1].empty() && moves[L - 1].top() > note)
				{
					moves[L - 1].pop();
					cnt++;
				}
				// 누른 음의 프렛이 같을 때
				if (!moves[L - 1].empty() && moves[L - 1].top() == note)
					continue;
			}
			
		}
		moves[L - 1].push(note);
		cnt++;
		// cout << cnt << '\n';  // 디버깅
	}

	cout << cnt;
	return 0;
}