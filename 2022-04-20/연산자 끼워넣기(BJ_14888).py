from sys import stdin
input = stdin.readline
from itertools import permutations

MIN = -1000000000
MAX = 1000000000

def cal(N, nums, ops):
    res = nums[0]
    for i in range(N - 1):
        op = ops[i]
        if op == '+':
            res += nums[i + 1]
        elif op == '-':
            res -= nums[i + 1]
        elif op == '*':
            res *= nums[i + 1]
        else:
            res = int( res / nums[i + 1] )
            
    return res

    
def solution(N, nums, operator):
    candidates = []
    if N == 2:
        candidates = operator
    else:
        candidates = set(permutations(operator, N-1))
    
    answer_max = MIN
    answer_min = MAX
    
    for ops in candidates:
        result = cal(N, nums, ops)
        if result > answer_max:
            answer_max = result
        if result < answer_min:
            answer_min = result

    return [answer_max, answer_min]


N = int(input())
nums = []
for i in list(input().split()):
    nums.append(int(i))
op = list(input().split())
operator = []
for i in range(len(op)):
    tmp = int(op[i])
    if tmp == 0:
        continue
    else:
        for _ in range(tmp):
            if i == 0:
                operator.append('+')
            elif i == 1:
                operator.append('-')
            elif i == 2:
                operator.append('*')
            else:
                operator.append('/')

for i in solution(N, nums, operator):
    print(i)
