# 문자열 반복
# https://www.acmicpc.net/problem/2675

def repeat(n, repeat_str):
    result = ''
    for s in repeat_str:
        result += s*int(n)
    return result

num = int(input())

for _ in range(num):
    n, str = input().split(' ')
    print(repeat(n, str))
