#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int input;

bool cmp(pair<int, int>s1, pair<int, int> s2)
{
	return s1.first < s2.first;
}

bool findStudent(pair<int, int>s)
{
	return s.first == input;
}

int main()
{
	int n, m;
	// 입력
	cin >> n >> m;
	vector<pair<int, int>> v; // 후보 번호, 추천수
	// 연산
	while (m--)
	{
		cin >> input;
		for (int i = 0; i < n; i++)
		{
			auto it = find_if(v.begin(), v.end(), findStudent);
			if (it != v.end()) // 후보로 등록되어 있음
				it->second++;
			else // 처음 후보로 등록
			{
				if (v.size() < n) // 후보 < n
					v.push_back({ input, 1 });
				else // 후보 == n
				{
					int min_candidate = 1000;
					// 가장 적게 추천된 후보의 추천 수
					for (int j = 0; j < n; j++)
						min_candidate = min(min_candidate, v[j].second);
					// 앞에서 부터 (등록 시간 순)
					for(int j=0; j<n; j++)
						if (v[j].second == min_candidate)
						{
							v.erase(v.begin() + j);
							v.push_back({ input, 1 });
							break;
						}
				}
			}				
		}
	}
	// 출력
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << ' ';
}