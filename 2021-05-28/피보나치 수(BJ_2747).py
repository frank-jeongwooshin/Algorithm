import sys
input = sys.stdin.readline

N = int(input())
fibo =[0] * 46
fibo[1] = 1

for i in range(2, 46):
    fibo[i] = fibo[i-2] + fibo[i-1]
print(fibo[N])
