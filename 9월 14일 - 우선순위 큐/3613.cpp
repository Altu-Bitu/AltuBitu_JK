#include <iostream>
#include <vector>
#include <string>

using namespace std;

int toJava(string s)
{
	vector <char> trans;
	for (int i = 0; i < s.size(); i++)
	{
		// 첫 문자/마지막 문자가 _인 경우
		if ((i == 0 && s[i] == '_') || (i == s.size() - 1 && s[i] == '_'))
		{
			cout << "Error!" << '\n';
			return 0;
		}
		// _
		else if (s[i] == '_')
		{
			// _가 연속으로 나오는 경우
			if ((s[i] == '_') && (s[i + 1] == '_'))
			{
				cout << "Error!" << '\n';
				return 0;
			}
			// _ + 대문자
			if (s[i + 1] >= 'A' && s[i + 1] <= 'Z')
			{
				cout << "Error!" << '\n';
				return 0;
			}
			trans.push_back(s[i + 1] - 'a' + 'A');
			i++;
		}
		// 소문자
		else if (s[i] >= 'a' && s[i] <= 'z')
			trans.push_back(s[i]);
		// 그 외의 문자
		else
		{
			cout << "Error!" << '\n';
			return 0;
		}
	}
	for (int i = 0; i < trans.size(); i++)
		cout << trans[i];
	return 0;
}

int toCPlusPlus(string s)
{
	vector <char> trans;
	for (int i = 0; i < s.size(); i++)
	{
		// 첫 문자가 대문자인 경우
		if (i == 0 && (s[i] >= 'A' && s[i] <= 'Z'))
		{
			cout << "Error!" << '\n';
			return 0;
		}
		// 대문자
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			trans.push_back('_');
			trans.push_back(s[i] - 'A' + 'a');
		}
		// 소문자
		else if (s[i] >= 'a' && s[i] <= 'z')
			trans.push_back(s[i]);
		// 그 외의 문자
		else
		{
			cout << "Error!" << '\n';
			return 0;
		}
	}
	for (int i = 0; i < trans.size(); i++)
		cout << trans[i];
	return 0;
}

int main()
{
	string s;
	cin >> s;
	if (string::npos != s.find("_"))
		toJava(s);
	else
		toCPlusPlus(s);
	return 0;
}