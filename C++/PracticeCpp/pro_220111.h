#pragma once
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

// 예산
class budget {
public:
    int solution(vector<int> d, int budget);
};

// 두 개 뽑아서 더하기
class sumTwo {
public:
    vector<int> solution(vector<int> numbers);
};

// 2016년
vector<string> day = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
vector<int> mon = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
class year2016 {
public:
    string solution(int a, int b);
};