#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    // 가장 큰 자리 수의 값을 최대로
     int idx = -1, digit = 0;
    while(digit < number.length() - k)
    {
        // 최대값을 찾는 시작 자리와 마지막 자리를 움직이며 검사
        char max_num = '0';
        for (int i = idx+1; i <= k+digit; i++)
        {
            //cout << i << "\n";
            if (number[i] > max_num)
            {
                max_num = number[i];
                idx = i;
            }            
        }
        answer += max_num;
        digit++;
    }
    return answer;
}

int main()
{
    // "1924", 2
    // "1231234", 3
    // "4177252841", 4
    string input = "4177252841";
    int k = 4;
    cout << solution(input, k) << '\n';
}