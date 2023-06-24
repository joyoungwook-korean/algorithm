# 피보나치 수 2 
# https://www.acmicpc.net/problem/2748

fibonacchi_list = []
 
num  = int(input())
tmp = 0
for n in range(num+1):
    if n ==0:
        tmp = 0
    elif n <= 2:
        tmp = 1
    else:
        tmp = fibonacchi_list[-1] + fibonacchi_list[-2]
    fibonacchi_list.append(tmp)

print(fibonacchi_list[-1])