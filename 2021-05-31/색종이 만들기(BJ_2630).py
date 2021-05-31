import sys
input = sys.stdin.readline

N = int(input())
paper = []
for _ in range(N):
    tmp = list(map(int, input().split()))
    paper.append(tmp)
white = 0
blue = 0

def check(x, y, n):
    global white, blue
    
    flag = paper[x][y]
    for i in range(n):
        for j in range(n):
            if paper[x+i][y+j] != flag:
                flag = 2
                break

    if flag == 0:
        white += 1
        return
    if flag == 1:
        blue += 1
        return
    
    n = n//2
    check(x, y, n)
    check(x+n, y, n)
    check(x, y+n, n)
    check(x+n, y+n, n)

check(0, 0, N)
print(white)
print(blue)
