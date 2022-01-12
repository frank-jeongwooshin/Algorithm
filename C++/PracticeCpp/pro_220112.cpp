#include "pro_220112.h"

int minSquare::solution(vector<vector<int>> sizes)
{
    int answer = 0;
    int width, height;
    width = height = 0;

    for (auto s : sizes) {
        if (s[0] > s[1]) {
            width = width > s[0] ? width : s[0];
            height = height > s[1] ? height : s[1];
        }
        else {
            width = width > s[1] ? width : s[1];
            height = height > s[0] ? height : s[0];
        }
    }
    answer = width * height;
    return answer;
}

int mod1::solution(int n)
{
    int answer = 0;
    for (int i = 2; i < n; ++i) {
        if (n % i == 1) {
            answer = i;
            break;
        }
    }
    return answer;
}
