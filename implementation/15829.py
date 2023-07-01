#hashing
# https://www.acmicpc.net/problem/15829

input()
str_list = list(input())
result = 0

for i in range(len(str_list)):
    tmp = (ord(str_list[i]) - 96) * (31 **(i))
    result += tmp
print(result%1234567891)