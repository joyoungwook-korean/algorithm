# 알파벳 찾기
# https://www.acmicpc.net/problem/10809

in_str = input()

result_list = [-1 for _ in range(0,26)]

for i in range(0, len(in_str)):
    tmp = ord(in_str[i])-97
    if result_list[tmp] == -1:
        result_list[tmp] = i 

print(*result_list)
    