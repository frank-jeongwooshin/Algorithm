import sys
input = sys.stdin.readline

X, Y = map(int, input().split())

answer = round(1000 / (Y/X), 3)

for _ in range(int(input())):
    x, y = map(int, input().split())

    tmp = round(1000 / (y/x), 2)
    answer = min(answer, tmp)

print('%.2f' % answer)
