#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string max_string(string mk)
{
	string max_mk;
	int cnt = 0, flag = 0, i = 0;
	while (i < mk.length())
	{
		char letter = mk[i];
		if (letter == 'M')
		{
			// 연속된 M의 개수
			while (i < mk.length())
			{
				letter = mk[i];
				if (letter == 'M')
					cnt++;
				i++;
				// 연속된 M을 끝내는 K
				if (letter == 'K')
				{
					flag = 1;
					break;
				}	
			}
			// K로 끝날 때
			if (flag == 1)
			{
				max_mk += "5";
				while (cnt > 0) {
					max_mk += "0";
					cnt--;
				}
			}
			// M으로 끝날 때
			else
			{
				while (cnt > 0) {
					max_mk += "1";
					cnt--;
				}
			}
			flag = 0;
		}
		else
		{
			max_mk += "5";
			i++;
		}
	}
	return max_mk;
}

string min_string(string mk)
{
	string min_mk;
	int i = 0, cnt = 0, flag = 0;
	while (i < mk.length())
	{
		char letter = mk[i];
		if (letter == 'M')
		{
			// 연속된 M의 개수
			while (i < mk.length())
			{
				letter = mk[i];
				if (letter == 'M')
					cnt++;
				i++;
				// 연속된 M을 끝내는 K
				if (letter == 'K')
				{
					flag = 1;
					break;
				}
			}
			min_mk += "1";
			cnt--;
			while (cnt > 0) {
				min_mk += "0";
				cnt--;
			}
			if (flag == 1)
				min_mk += "5";
			flag = 0;
		}
		else
		{
			min_mk += "5";
			i++;
		}	
	}
	return min_mk;
}

int main()
{
	string mk;
	cin >> mk;
	cout << max_string(mk) << '\n' << min_string(mk) << '\n';
}