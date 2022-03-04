#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> snack;

// 과자 자르기
int cut(int len) {
	int cnt = 0;
	for (int i = snack.size() - 1; i >= 0; i--)
		cnt += snack[i] / len;
	return cnt;
}

int upperSearch(int left, int right, int target) {
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int allocate = cut(mid);
		if ( allocate < target)
			right = mid - 1;
		else if (allocate >= target) {
			ans = mid;
			left = mid + 1;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n;
	cin >> m >> n;
	snack.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> snack[i];
	sort(snack.begin(), snack.end());
	cout << upperSearch(1, snack[n - 1], m);

}