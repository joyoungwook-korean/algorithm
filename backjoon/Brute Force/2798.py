# 블랙잭
# https://www.acmicpc.net/problem/2798

n, total = map(int, input().split(' '))
nums = list(map(int, input().split(' ')))

result = 0

for i in range(n-2):
    for j in range(i+1,n-1):
        for k in range(j+1, n):
            if result < nums[i] + nums[j] + nums[k] <= total:
                result = nums[i] + nums[j] + nums[k]
                

print(result)


