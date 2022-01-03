#include "pro_220103.h"

int DotProduct::solution(vector<int> a, vector<int> b)
{
    int answer = 0;
    for (int i = 0; i < a.size(); ++i) {
        answer += (a[i] * b[i]);
    }
    return answer;
}

bool MakePrime::isPrime(int num)
{
    if (num == 1) {
        return true;
    }
    for (int i = 2; i < int(sqrt(num)) + 1; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int MakePrime::solution(vector<int> nums)
{
    int answer = 0;

    int numsLength = nums.size();
    for (int i = 0; i < numsLength - 2; ++i) {
        for (int j = i + 1; j < numsLength - 1; ++j) {
            for (int k = j + 1; k < numsLength; ++k) {
                if (isPrime(nums[i] + nums[j] + nums[k])) {
                    ++answer;
                }
            }
        }
    }

    return answer;
}

string havingChancePlayer::solution(vector<string> participant, vector<string> completion)
{
    string answer = "";

    map<string, int> names;
    for (int i = 0; i < completion.size(); ++i) {
        if (names.find(participant[i]) == names.end()) {
            names.insert({ participant[i], 1 });
        }
        else {
            names[participant[i]] += 1;
        }

        if (names.find(completion[i]) == names.end()) {
            names.insert({ completion[i], -1 });
        }
        else {
            names[completion[i]] -= 1;
        }
    }
    if (names.find(participant[participant.size() - 1]) == names.end()) {
        return participant[participant.size() - 1];
    }
    else {
        names[participant[participant.size() - 1]] += 1;
    }
    for (auto name : names) {
        if (0 != name.second) {
            return name.first;
        }
    }
}

vector<int> Exam::solution(vector<int> answers)
{
    vector<int> answer;
    int student1[5] = { 1, 2, 3, 4, 5 };
    int student2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int student3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    int s1 = 0, s2 = 0, s3 = 0;

    for (int i = 0; i < answers.size(); ++i) {
        int ans = answers[i];
        if (ans == student1[i % 5]) {
            ++s1;
        }
        if (ans == student2[i % 8]) {
            ++s2;
        }
        if (ans == student3[i % 10]) {
            ++s3;
        }
    }
    if (s1 > s2) {
        if (s1 > s3) {
            answer.push_back(1);
        }
        else if (s1 < s3) {
            answer.push_back(3);
        }
        else {
            answer.push_back(1);
            answer.push_back(3);
        }
    }
    else if (s1 < s2) {
        if (s2 > s3) {
            answer.push_back(2);
        }
        else if (s2 < s3) {
            answer.push_back(3);
        }
        else {
            answer.push_back(2);
            answer.push_back(3);
        }
    }
    else {
        if (s1 > s3) {
            answer.push_back(1);
            answer.push_back(2);
        }
        else if (s1 < s3) {
            answer.push_back(3);
        }
        else {
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
    }

    return answer;
}
