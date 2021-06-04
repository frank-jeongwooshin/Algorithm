import sys
input = sys.stdin.readline

N, r, c = map(int, input().split())
nums = [[0] * (2**N) for _ in range(2**N)]

for i in nums:
    print(i)
nums[r][c] = 13
print(nums[r][c])
