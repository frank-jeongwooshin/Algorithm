import sys
input = sys.stdin.readline

N = int(input())
w = 4 * N - 3
iteration = 4 * (N-1) -1
star = [[' '] * w for _ in range(w+2)]

def draw_star0(x, y):
    global w
    for i in range(1, w):
        star[x-i][y] = '*'
    x -= w-1
    w -= 2
    return x, y

def draw_star1(x, y):
    global w
    for i in range(1, w):
        star[x][y-i] = '*'
    y -= w-1
    return x, y
        
def draw_star2(x, y):
    global w
    for i in range(1, w):
        star[x+i][y] = '*'
    x += w-1
    w -= 2
    return x, y

def draw_star3(x, y):
    global w
    for i in range(1, w):
        star[x][y+i] = '*'
    y += w-1
    return x, y

if N == 1:
    print('*')
else:
    for i in range(w):
        star[0][i] = '*'
        star[-1][i] = '*'
        star[i+1][0] = '*'

    x, y = w+1, w-1
    for i in range(iteration):
        tmp = i % 4
        if tmp == 0:
            x, y = draw_star0(x, y)
        elif tmp == 1:
            x, y = draw_star1(x, y)
        elif tmp == 2:
            x, y = draw_star2(x, y)
        else:
            x, y = draw_star3(x, y)

for s in star:
    tmp = ''
    for i in s:
        tmp += i
    print(tmp.rstrip())
