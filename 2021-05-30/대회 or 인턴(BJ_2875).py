import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())
answer = 0

while True:
    if N + M <= K:
        answer = 0
        break
    
    if N <= 0 or M <= 0:
        answer = 0
        break
    
    if N // 2 > M:
        tmp_r = N - (2 * M)
        N -= tmp_r
        K -= tmp_r
    elif N // 2 < M:
        tmp_r = M - (N // 2)
        M -= tmp_r
        K -= tmp_r

    if N % 2 == 1:
        N -= 1
        K -= 1
        
    if K <= 0:
        if N // 2 >= M:
            answer = M
        else:
            answer = N // 2
        break
        
    if M >= N:
        tmp_rest = M - (N // 2)
        M = N // 2
        
        if tmp_rest >= K:
            answer = M
            break
        K -= tmp_rest

    if K >= 3:
        N -= 2
        M -= 1
        K -= 3
    else:
        answer = M-1
        break

print(answer)
