# https://www.acmicpc.net/problem/11047

count, total = map(int, input().split())
money = [int(input()) for _ in range(count)]

result = 0
money.reverse()
for n in money:
    result += total // n
    total = total % n

print(result)

