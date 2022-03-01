#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string num_min="9876543210", num_max = "0";
int k;
vector<char> v;
bool check_num[10];
void backtracking(int cnt, string num)
{
	// stoi아닌 stoll로 해야 한다.
	if (cnt == k+1)
	{
		num_max = stoll(num) > stoll(num_max) ? num : num_max;
		num_min = stoll(num) < stoll(num_min) ? num : num_min;
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (!check_num[i])
		{
			if ((num.size()== 0) || (v[cnt] == '<' && num[num.size() - 1] - '0' < i) || (v[cnt] == '>' && num[num.size() - 1] - '0' > i))
			{
				num = num + to_string(i);
				check_num[i] = true;
				backtracking(cnt + 1, num);
				num = num.substr(0, num.size() - 1);
				check_num[i] = false;
			}
		}			
	}
}

int main()
{
	// 입출력 속도
	ios::sync_with_stdio(0);
	cin.tie(0);
	// 입력
	cin >> k;
	v.assign(k+1, ' ');
	for (int i = 1; i <= k; i++)
		cin >> v[i];
	// 연산
	backtracking(0, "");
	// 출력
	cout << num_max << '\n' << num_min << '\n';
	return 0;
	
}