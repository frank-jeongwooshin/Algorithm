#include "pro_220111.h"

int budget::solution(vector<int> d, int budget)
{
    int answer = 0;
    sort(d.begin(), d.end());

    for (auto n : d) {
        budget -= n;
        if (budget < 0) {
            break;
        }
        ++answer;
    }
    return answer;
}

vector<int> sumTwo::solution(vector<int> numbers)
{
    vector<int> answer;
    set<int> nums;
    int numsLen = numbers.size();

    for (int i = 0; i < numsLen; ++i) {
        for (int j = i + 1; j < numsLen; ++j) {
            nums.insert(numbers[i] + numbers[j]);
        }
    }
    for (auto n : nums) {
        answer.push_back(n);
    }
    sort(answer.begin(), answer.end());
    return answer;
}

string year2016::solution(int a, int b)
{
    int numOfDays = 0;
    for (int i = 1; i < a; ++i) {
        numOfDays += mon[i - 1];
    }
    numOfDays += b - 1;
    numOfDays = (4 + numOfDays) % 7;

    return day[numOfDays];
}
