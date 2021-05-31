import sys
input = sys.stdin.readline

N = int(input())
w = 4 * N - 3
star = [[' '] * w for _ in range(w+2)]

print(len(star), 'height')
print(len(star[0]), 'width')
