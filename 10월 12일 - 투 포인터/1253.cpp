#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, cnt = 0;
	// 입력
	cin >> N;
	vector<int> a(N, 0);
	for (int i = 0; i < N; i++)
		cin >> a[i];
	// 연산
	// 정렬
	sort(a.begin(), a.end());
	for (int i = 0; i < N; i++)
	{
		int left = 0, right = N - 1;
		while (left < right)
		{
			// 합이 같은 경우
			if (a[left] + a[right] == a[i])
			{
				// 자기 자신을 포함하는 경우 (0)
				if (left == i)
				{
					left++;
					continue;
				}	
				else if (right == i)
				{
					right--;
					continue;
				}
				cnt++;
				break;
			}
			// 더 크니까 오른쪽 포인터를 왼쪽으로
			else if (a[left] + a[right] > a[i])
				right--;
			// 더 작으니까 왼쪽 포인터를 오른쪽으로
			else
				left++;
		}
	}
	// 출력
	cout << cnt << '\n';
}