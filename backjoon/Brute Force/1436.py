# 영화감독 숌
# https://www.acmicpc.net/problem/1436

n = int(input())
num = 665
count = 0 
while count != n:
    num +=1
    if '666' in str(num):
        count +=1
print(num)