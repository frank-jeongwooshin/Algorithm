import sys
input = sys.stdin.readline

o, i = map(int, input().split())
answer = [i]
for j in range(3):
    o, i = map(int, input().split())

    tmp = answer[j] + i - o
    answer.append(tmp)

print(max(answer))
