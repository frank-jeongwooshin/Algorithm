#include "pro_220109.h"

int poketmon::solution(vector<int> nums)
{
    int answer = nums.size() / 2;
    set<int> uniqueNums;

    for (auto num : nums) {
        uniqueNums.insert(num);
    }
    int len = uniqueNums.size();

    if (len < answer) {
        answer = len;
    }
    return answer;
}

vector<int> failPercent::solution(int N, vector<int> stages)
{
    vector<int> answer;
    vector<pair<double, int>> fail;
    for (int i = 1; i <= N; i++) {
        double a = 0, b = 0;
        for (int j = 0; j < stages.size(); j++) {
            if (stages[j] == i) a += 1;
            if (stages[j] >= i) b += 1;
        }
        if (b != 0)
            fail.push_back(make_pair(a / b, i));
        else if (b == 0)
            fail.push_back(make_pair(0, i));
    }
    sort(fail.begin(), fail.end(), cmp);
    auto it = fail.begin();
    for (it = fail.begin(); it != fail.end(); it++)
        answer.push_back(it->second);
    return answer;
}

bool checkDivisor::divisor(int num)
{
    if (num == 1) {
        return false;
    }
    int result = 2;
    for (int i = 2; i < num; ++i) {
        if (num % i == 0) {
            ++result;
        }
    }
    if (result % 2 == 0) {
        return true;
    }
    else {
        return false;
    }
}

int checkDivisor::solution(int left, int right)
{
    int answer = 0;
    for (int i = left; i <= right; ++i) {
        if (true == divisor(i)) {
            answer += i;
        }
        else {
            answer -= i;
        }
    }
    return answer;
}
