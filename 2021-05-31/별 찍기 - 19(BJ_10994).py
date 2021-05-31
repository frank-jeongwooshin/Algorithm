import sys
input = sys.stdin.readline

N = int(input())

star = [[' '] * (4 * N - 3) for _ in range(8 * N - 7)]

def draw_star(x, y, n):
    if n == 1:
        star[x][y] = '*'
        return

    for i in range(0, 8*n-7, 2):
        if i == 0 or i == 8*n-8:
            for j in range(4*n-3):
                star[x+i][y+j] = '*'
        else:
            star[x+i][y] = '*'
            star[x+i][y+(4*n-4)] = '*'
    
    x = x + 4
    y = y + 2
    draw_star(x, y, n-1)

draw_star(0, 0, N)
for s in star:
    if s[0] == ' ': continue
    tmp = ''
    for i in s:
        tmp += i
    print(tmp.rstrip())
