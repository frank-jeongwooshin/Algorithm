#include "pro_220110.h"

vector<int> reveseTrit::ReverseTrit(int n) {
    vector<int> result;
    while (n >= 3) {
        result.push_back(n % 3);
        n = int(n / 3);
    }
    result.push_back(n);
    return result;
}

int reveseTrit::solution(int n) {
    int answer = 0;
    vector<int> trit = ReverseTrit(n);
    int tritLen = trit.size();

    for (int i = 0; i < tritLen; ++i) {
        answer += pow(3, tritLen - i - 1) * trit[i];
    }

    return answer;
}