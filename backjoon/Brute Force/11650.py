# 좌표 정렬하기
# https://www.acmicpc.net/problem/11650


n =  int(input())
data = []
for _ in range(n):
    x,y = map(int, input().split())
    data.append((x,y))

print(data)
resultDic = {}
resultArr = []
def showResult():
    for value in data:
        resultArr.append(value[0])
        resultDic[value[0]] = value[1]
        
showResult()
print(resultArr)
print(resultDic)

            