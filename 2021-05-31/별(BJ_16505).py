import sys
input = sys.stdin.readline

N = int(input())
star = [[' '] * ((2**N)) for _ in range(2**N)]

def draw_star(x, y, n):
    if n == 1:
        star[x][y] = '*'
        return

    n = n//2
    draw_star(x, y, n)
    draw_star(x+n, y, n)
    draw_star(x, y+n, n)

draw_star(0, 0, 2**N)

for r in star:
    tmp = ''
    
    for j in r:
        tmp += j
    print(tmp.rstrip())

