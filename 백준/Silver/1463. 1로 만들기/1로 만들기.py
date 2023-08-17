# https://www.acmicpc.net/problem/1463

import sys

num = int(input())

memo = [0] * (num+1)

for n in range(2, num + 1):
    memo[n] = memo[n-1] + 1

    if n % 2 == 0:
        memo[n] = min(memo[n], memo[n//2] + 1)
    if n % 3 == 0:
        memo[n] = min(memo[n], memo[n//3] + 1)

print(memo[num])