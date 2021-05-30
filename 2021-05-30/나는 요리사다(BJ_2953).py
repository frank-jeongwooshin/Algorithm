import sys
input = sys.stdin.readline

idx = 0
score = 0
for i in range(1, 6):
    tmp_s = list(map(int, input().split()))
    tmp = sum(tmp_s)
    
    if score < tmp:
        idx = i
        score = tmp
        
print(idx, score)
    
