# 나머지
# https://www.acmicpc.net/problem/3052

numbers = [int(input()) for _ in range(10)]
result={}

for n in numbers:
    if result.get(str(n%42)) is None:
        result[str(n%42)] = 1

print(len(result))
