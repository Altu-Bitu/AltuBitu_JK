#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>

using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	vector<string> v(n, "");
	set<char> s;
	// 입력
	for (int i = 0; i < n; i++)
		cin >> v[i];
	// 연산
	for (int i = 1; i <= n-1; i++)
	{
		int add = 0, sub = 0, diff = 0;
		// 구성 요소 
		map<char, int> m; // 첫 번째 단어
		// 첫 번째 단어에 있는 문자들을 맵에 넣는다
		for (int t = 0; t < v[0].size(); t++)
		{
			m[v[0][t]]++;
			s.insert(v[0][t]);
		}
		// 문자의 종류
		for (int j = 0; j < v[i].size(); j++)
			if (m[v[i][j]] == 0) // 첫 번째 단어에 없는 문자
				diff++;
		// map에서 비교하고자 하는 단어에 있는 문자들 제외
		// 음수이면 추가된 것, 양수이면 없는 것
		for (int j = 0; j < v[i].size(); j++)
			m[v[i][j]]--;

		// 문자의 개수
		for (auto iter= s.begin(); iter!=s.end(); iter++)
		{
			if (m[*iter] < 0)
				add += abs(m[*iter]); // 추가된 것
			else if(m[*iter] > 0)
				sub += abs(m[*iter]); // 빠진 것
		}

		//cout << v[i] << " diff:" << diff << " add:" << add << " sub:" << sub << '\n';
		if ((diff == 1 && sub == 1 && add == 0) || (add == 1 && sub == 1 && diff == 0)) // 한 문자 바꿔서
			cnt++;
		if (diff + add + sub <= 1) // 한 문자 더하거나 빼서
			cnt++;
		//cout << "CNT" << cnt << '\n';
	}
	// 출력
	cout << cnt << '\n';
}