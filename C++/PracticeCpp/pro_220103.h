#pragma once
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

// 내적
class DotProduct {
public:
    int solution(vector<int> a, vector<int> b);
};

// 소수 만들기
class MakePrime {
public:
    bool isPrime(int num);
    int solution(vector<int> nums);
};

// 완주하지 못한 선수
class havingChancePlayer {
public:
    string solution(vector<string> participant, vector<string> completion);
};

// 모의 고사
class Exam {
public:
    vector<int> solution(vector<int> answers);
};