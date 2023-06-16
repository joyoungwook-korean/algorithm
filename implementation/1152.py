# 단어의 개수
# https://www.acmicpc.net/problem/1152

str = input().split(' ')

blank_list = [s for s in str if s != ""]
print(len(blank_list))