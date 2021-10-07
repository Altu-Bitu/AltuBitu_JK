#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int r, c, cnt = 0;

// 색종이를 나누는 함수
void divide(int size, int row, int col) {
	// Conquer
	if (row == r && col == c) {
		cout<<cnt<<'\n';
		return;
	}

	// Divide: 색종이 4등분하기
	if ((row <= r && r < row + size) && (col <= c && c < col + size))
	{
		int sub_size = size / 2;
		// (0, 0), (0, ss), (ss, 0), (ss, ss)
		for (int i = 0; i < size; i += sub_size) {
			for (int j = 0; j < size; j += sub_size) {
				divide(sub_size, row + i, col + j);
				//cout << "Divide " << "size: " << size << " row: " << row << " col: " << col << '\n';
				//cout << "cnt: " << cnt << '\n';
			}
		}
	}
	else // (r, c) 보다 먼저 탐색된 칸의 수 더하기
		cnt += size * size;
}

int main() {
	int n;
	cin >> n >> r >> c;
	divide(pow(2, n), 0, 0);
}