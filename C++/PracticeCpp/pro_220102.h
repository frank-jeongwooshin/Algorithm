#pragma once
#include <string>
#include <vector>
#include <cctype>
#include <math.h>

// 숫자 문자열과 영단어
class numString_EngWord
{
public:
	std::string convertNum(std::string s);
	int solution(std::string s);
};

// 크레인 인형뽑기 게임
class PuppetDraw {
public:
	int solution(std::vector<std::vector<int>> board, std::vector<int> moves);
};

// 없는 숫자 더하기
class PlusNoNums {
public:
	int solution(std::vector<int> numbers);
};

// 음양 더하기
class AddAbsolutes {
public:
	int solution(std::vector<int> absolutes, std::vector<bool> signs);
};