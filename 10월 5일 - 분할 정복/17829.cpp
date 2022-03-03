#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pooling(vector<int> tmp)
{
	sort(tmp.begin(), tmp.end(), greater<>());
	return tmp[1];
}

int main() {
	int n;
	// 입력
	cin >> n;
	vector<vector<int>> matrix;
	matrix.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
	vector<vector<int>> matrix2;
	// 연산
	while(n>1)
	{
		n /= 2;
		matrix2.assign(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				vector<int> tmp = { matrix[i * 2][j * 2], matrix[i * 2 + 1][j * 2], matrix[i * 2][j * 2 + 1], matrix[i * 2 + 1][j * 2 + 1] };
				matrix2[i][j] = pooling(tmp);
			}
		}
		matrix.assign(n, vector<int>(n, 0));
		matrix = matrix2;
	}
	// 출력
	cout << matrix[0][0] << '\n';
}