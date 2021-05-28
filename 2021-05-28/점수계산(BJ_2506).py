import sys
input = sys.stdin.readline

N = int(input())
nums = list(map(int, input().split()))

answer = 0
score = 1

for i in nums:
    if i == 1:
        answer += score
        score += 1
    else:
        score = 1
print(answer)
