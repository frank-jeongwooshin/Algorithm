import sys
input = sys.stdin.readline

answer = ['D', 'C', 'B', 'A', 'E']
for _ in range(3):
    a, b, c, d = map(int, input().split())

    tmp = a + b + c + d
    print(answer[tmp])
