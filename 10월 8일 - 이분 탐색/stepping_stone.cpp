#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int skip(int friends, vector<int> stones)
{
	int cnt = 0, max_stone = 0;
	// 0이하의 값이 연속인 징검다리의 최대 개수
	for (int i = 0; i < stones.size(); i++)
	{
		// friends번째 친구가 건너기 전 상태를 확인
		if (stones[i] - (friends - 1) <= 0)
			cnt++;
		else
			cnt = 0;
		max_stone = max(max_stone, cnt);
	}
	return max_stone;
}

int solution(vector<int> stones, int k) {
	int answer = 0;
	int left = 1, right = *max_element(stones.begin(), stones.end());
	while (left <= right) {
		int mid = (left + right) / 2;
		int empty_stones = skip(mid, stones);
		if (empty_stones < k)
		{
			left = mid + 1;
			answer = mid;
		}
		else if (empty_stones >= k)
			right = mid - 1;
	}
	return answer;
}

int main() {
	vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
	int k = 3;
	cout << solution(stones, k);

}