#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 8;

int n, m;
int num[SIZE]; 
bool check[SIZE + 1];
vector<int> v;

void backtracking(int cnt) { 
	if (cnt == m) { 
		for (int i = 0; i < cnt; i++)
			cout << num[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		num[cnt] = v[i]; 
		check[i] = true; 
		backtracking(cnt + 1); 
		check[i] = false; 
	}
}

int main() {
	cin >> n >> m;
	int input;
	// set에 저장 (중복 없애고 오름차순)
	set<int> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		s.insert(input);
	}
	n = s.size();
	// set의 원소들 vector에 저장
	v.push_back(0);
	for (auto iter = s.begin(); iter != s.end(); iter++)
		v.push_back(*iter);
	backtracking(0);
	return 0;
}