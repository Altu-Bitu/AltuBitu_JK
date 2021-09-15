#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int previous = -1;
    stack<int> s;
    for (int i = 0; i < moves.size(); i++)
    {
        int crane = moves[i] - 1;
        for (int k = 0; k < board.size(); k++)
        {
            if (board[k][crane] != 0)
            {
                //cout << board[k][crane] << '\n';
                if(!s.empty())
                    previous = s.top();
                s.push(board[k][crane]);
                if (board[k][crane] == previous)
                {
                    s.pop();
                    while (!s.empty() && board[k][crane] == s.top())
                    {
                        s.pop();
                        answer++;
                    }
                }
                else
                    s.push(board[k][crane]);
                board[k][crane] = 0;
                previous = -1;
                break;
            }
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> board = { {0, 0, 0, 0, 0},{0, 0, 1, 0, 3 },{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
    vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4};

    cout << solution(board, moves);

}