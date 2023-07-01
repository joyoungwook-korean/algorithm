# 달팽이는 올라가고 싶다
# https://www.acmicpc.net/problem/2869

import math

m, n, finish = map(int, input().split())
result = (finish-n) / (m-n)
print(math.ceil(result))