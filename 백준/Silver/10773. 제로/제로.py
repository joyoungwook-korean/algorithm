# 제로 
# https://www.acmicpc.net/problem/10773

input_num = int(input())

result_arr = []
for _ in range(input_num):
    n = int(input())
    if n == 0:
        result_arr.pop()
    else:
        result_arr.append(n)

result = 0
if len(result_arr) != 0:
  for i in result_arr:
        result = result+i

print(result)

    