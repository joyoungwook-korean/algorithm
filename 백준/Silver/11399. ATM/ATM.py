# https://www.acmicpc.net/problem/11399

n = int(input())
arr = list(map(int, input().split()))
arr.sort()
result = 0
pre_total = 0
for i in arr:
    pre_total = pre_total + i
    result += pre_total
print(result)