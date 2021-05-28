import sys
input = sys.stdin.readline

even = []

for _ in range(7):
    tmp = int(input())
    if tmp % 2 == 1:
        even.append(tmp)

if even:
    print(sum(even))
    print(min(even))
else:
    print(-1)
