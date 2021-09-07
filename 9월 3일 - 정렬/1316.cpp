#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, not_group_word = 0;
	cin >> n;
	vector<string> word;
	vector<int> temp;
	word.assign(n, "");
	temp.assign(26, 0);
	for (int i = 0; i < word.size(); i++)
		cin >> word[i];
	for (int i = 0; i < word.size(); i++)
	{
		for (int j = 0; j < word[i].size(); j++)
		{
			if (temp[(int)word[i][j]-'a'] == 1 && (int)word[i][j-1] != (int)word[i][j])
			{
				not_group_word += 1;
				break;
			}
			temp[(int)word[i][j] - 'a'] = 1;
		}
		temp.assign(26, 0);
	}
	cout << n - not_group_word;
}