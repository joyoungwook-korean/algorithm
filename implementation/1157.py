# 단어 공부
# https://www.acmicpc.net/problem/1157

inputStr = input().upper()
mapStr = {}

for s in inputStr:
    if s in mapStr:
        mapStr[s] += 1
    else:
        mapStr[s] = 1
result = ''
tmpMax = 0
for c in mapStr:
    if mapStr[c] > tmpMax:
        tmpMax = mapStr[c]
        result = c
    elif mapStr[c] == tmpMax:
        result = '?'

print(result)