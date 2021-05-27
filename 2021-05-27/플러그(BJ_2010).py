import sys
input = sys.stdin.readline

N = int(input())

answer = 1
for _ in range(N):
    tmp = int(input())
    if tmp == 1:
        continue

    answer += (tmp-1)
        
print(answer)
