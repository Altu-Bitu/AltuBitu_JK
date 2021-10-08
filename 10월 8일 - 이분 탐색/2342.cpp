#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> lecture;

// 강의 자르기
int cut(int storage, int target) {
	int cnt = 1, disk = 0;
	// cout << "store:" << storage <<'\n';
	for (int i = 0; i < lecture.size(); i++)
	{
		if (disk +lecture[i] <= storage) // 기존의 블루레이에 강의 넣기
			disk += lecture[i];
		else if (lecture[i] > storage) // 블루레이 크기보다 긴 강의가 있는 경우
			return target + 1;
		else // 새로운 블루레이에 강의 넣기
		{
			disk = lecture[i];
			cnt++;
		}
	}
	// cout << "cnt: " << cnt << '\n';
	return cnt;
}

int lowerSearch(int left, int right, int target) 
{
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int blueray = cut(mid, target); // 블루레이의 크기: mid
		// 블루레이 최소 크기 구하기
		if (blueray <= target) // m개 이하의 블루레이에 담을 수 있는 경우
		{
			ans = mid;
			right = mid - 1;
		}	
		else if (blueray > target) // m개보다 많은 블루레이가 필요한 경우
			left = mid + 1;
	}
	return ans;
}

int main() 
{
	int n, m, sum = 0;
	cin >> n >> m;
	lecture.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> lecture[i];
		sum += lecture[i];
	}
	// 블루레이에 강의 최소 1분, 최대 sum분
	cout << lowerSearch(1, sum, m);
}
