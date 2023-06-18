# 숫자의 개수
# https://www.acmicpc.net/problem/2577

result_list = [0,0,0,0,0,0,0,0,0,0]
n = 1
for _ in range(3):
    n *= int(input())

for s in str(n):
    result_list[int(s)] += 1

for i in result_list:
    print(i)