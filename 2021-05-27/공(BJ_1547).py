import sys
input = sys.stdin.readline

M = int(input())

ball = [1, 2, 3]
for _ in range(M):
    x, y = map(int, input().split())

    if x == y: continue
    x = ball.index(x)
    y = ball.index(y)
    ball[x], ball[y] = ball[y], ball[x]

print(ball[0])
