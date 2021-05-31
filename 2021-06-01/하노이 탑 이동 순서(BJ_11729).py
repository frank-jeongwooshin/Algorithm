import sys
input = sys.stdin.readline

N = int(input())

def hanoi(n, start, end, mid):
    if n == 1:
        print(start, end)
    else:
        hanoi(n-1, start, mid, end)
        print(start, end)
        hanoi(n-1, mid, end, start)

print((2**N)-1)
hanoi(N, 1, 3, 2)
        
