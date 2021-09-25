#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000;

int main()
{
	int t, k, num=0;
	vector<int> triangle;
	// 삼각수 계산
	// i*(i+1)/2 로 구현해도 됨
	for(int i=1; num<1000; i++)
	{
		num += i;
		triangle.push_back(num);
	}

	cin >> t;
	while (t--)
	{
		cin >> k;
		int ans = 0;
		for (int i = 0; i < triangle.size(); i++)
			for (int j = 0; j < triangle.size(); j++)
				for (int p = 0; p < triangle.size(); p++)
					if (k == (triangle[i] + triangle[j] + triangle[p]))
						ans = 1;
		cout << ans << '\n';
	}
	return 0;
}