#include "pro20220310.h"

long long pro20220310::getInsufficientAmount(int price, int money, int count)
{
    long long answer = 0;
    long long totalPrice = price * (long long)((count * (count + 1)) / 2);
    if (money < totalPrice)
    {
        answer = totalPrice - money;
    }
    return answer;
}
