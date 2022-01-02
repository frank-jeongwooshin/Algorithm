#include "pro_220102.h"

std::string numString_EngWord::convertNum(std::string s)
{
    if (3 > s.size()) {
        return s;
    }
    if ("zero" == s) {
        return "0";
    }
    else if ("one" == s) {
        return "1";
    }
    else if ("two" == s) {
        return "2";
    }
    else if ("three" == s) {
        return "3";
    }
    else if ("four" == s) {
        return "4";
    }
    else if ("five" == s) {
        return "5";
    }
    else if ("six" == s) {
        return "6";
    }
    else if ("seven" == s) {
        return "7";
    }
    else if ("eight" == s) {
        return "8";
    }
    else if ("nine" == s) {
        return "9";
    }
    else {
        return s;
    }
}

int numString_EngWord::solution(std::string s)
{
    int answer = 0;

    int length = s.size();
    std::string tempNum = "";
    std::vector<int> numbers;
    for (int i = 0; i < length; ++i)
    {
        if (isdigit((s[i])))
        {
            numbers.push_back(s[i] - '0');
            continue;
        }
        tempNum += s[i];
        std::string check = convertNum(tempNum);

        if (2 > check.size()) {
            if (isdigit(check[0])) {
                numbers.push_back(check[0] - '0');
                tempNum = "";
            }
        }
    }

    int power = numbers.size();
    for (int i = 0; i < power; ++i) {
        answer += (numbers[i] * pow(10, power - i - 1));
    }
    return answer;
}

int PuppetDraw::solution(std::vector<std::vector<int>> board, std::vector<int> moves)
{
    int answer = 0;

    std::vector<int> basket;
    int board_size = board.size();

    // moves
    for (int i = 0; i < moves.size(); ++i)
    {
        int down = 0;
        while (down < board_size)
        {
            int tmp = board[down][moves[i] - 1];
            // 해당 칸에 없는 경우
            if (tmp == 0) {
                ++down;
                continue;
            }

            // 있는 경우 - 들어서 바구니에 옮겨야 함
            board[down][moves[i] - 1] = 0;
            basket.push_back(tmp);
            // basket 확인
            int basket_size = basket.size();
            if (basket_size > 1)
            {
                if (basket[basket_size - 1] == basket[basket_size - 2])
                {
                    basket.erase(basket.begin() + (basket_size - 1));
                    basket.erase(basket.begin() + (basket_size - 2));
                    answer += 2;
                    break;
                }
            }
            break;
        }
    }
    return answer;
}

int PlusNoNums::solution(std::vector<int> numbers)
{
    int answer = 45;
    for (int i = 0; i < numbers.size(); ++i)
    {
        answer -= numbers[i];
    }
    return answer;
}

int AddAbsolutes::solution(std::vector<int> absolutes, std::vector<bool> signs)
{
    int answer = 0;

    for (int i = 0; i < signs.size(); ++i) {
        if (signs[i]) {
            answer += absolutes[i];
        }
        else {
            answer -= absolutes[i];
        }
    }

    return answer;
}
