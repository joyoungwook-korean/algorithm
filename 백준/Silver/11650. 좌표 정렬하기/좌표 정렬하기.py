# 좌표 정렬하기
# https://www.acmicpc.net/problem/11650


n =  int(input())
data = []
for _ in range(n):
    x,y = map(int, input().split())
    data.append((x,y))

resultDic = {}
resultArr = []
def showResult():
    for value in data:
        resultArr.append(value[0])
        if value[0] in resultDic:
            resultDic[value[0]].append(value[1])
        else:
            resultDic[value[0]] = [value[1]]
def showDic(i, test):
    test.sort()
    for a in test:
        print(i, a)

showResult()
unique_list = list(set(resultArr))
unique_list.sort()
for i in unique_list:
    showDic(i, resultDic[i])


            