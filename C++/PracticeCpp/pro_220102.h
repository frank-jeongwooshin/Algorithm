#pragma once
#include <string>
#include <vector>
#include <cctype>
#include <math.h>

// ���� ���ڿ��� ���ܾ�
class numString_EngWord
{
public:
	std::string convertNum(std::string s);
	int solution(std::string s);
};

// ũ���� �����̱� ����
class PuppetDraw {
public:
	int solution(std::vector<std::vector<int>> board, std::vector<int> moves);
};

// ���� ���� ���ϱ�
class PlusNoNums {
public:
	int solution(std::vector<int> numbers);
};

// ���� ���ϱ�
class AddAbsolutes {
public:
	int solution(std::vector<int> absolutes, std::vector<bool> signs);
};