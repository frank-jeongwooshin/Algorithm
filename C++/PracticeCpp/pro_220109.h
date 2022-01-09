#pragma once
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// 포켓몬
class poketmon {
public:
    int solution(vector<int> nums);
};

// 실패율
class failPercent {
public:
    bool cmp(const pair<double, int>& a, const pair<double, int>& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;

    }

    vector<int> solution(int N, vector<int> stages);
};

// 약수의 개수와 덧셈
class checkDivisor {
public:
    bool divisor(int num);

    int solution(int left, int right);
};