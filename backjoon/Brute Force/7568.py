# 덩치
# https://www.acmicpc.net/problem/7568
import sys

n = int(input())
input_values = [list(map(int,input().split())) for _ in range(n)]

sorted_input_values_height = sorted(input_values, key=lambda x: x[0], reverse=True)
sorted_input_values_weight = sorted(input_values, key=lambda x: x[1], reverse=True) 


result = []
tmp_k =0
while tmp_k != n:
    for i in range(n):
     if sorted_input_values_height[i] == sorted_input_values_weight[i]:
        result.append(i+1)
     else:
        tmp_k = i + 1
        while sorted_input_values_height[i][1] > sorted_input_values_weight[tmp_k][1]:
            result.append(i+1)
            tmp_k += 1


print(result)          

    