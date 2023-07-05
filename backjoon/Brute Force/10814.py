# 나이순 정렬
# https://www.acmicpc.net/problem/10814

def makeMap(student):
    result = {}
    for s in student:
        if int(s[0]) in result:
            result.get(int(s[0])).append(s[1])
        else:
            result[int(s[0])] = [s[1]]
    return result


def sortAseending(studentMap):
    result = list(studentMap.keys())
    result.sort()
    return result


def printStudent(studentMap, sort):
    for n in sort:
        for s in studentMap.get(n):
            print(n, s)


student = [list(input().split(" ")) for _ in range(int(input()))]
studentMap = makeMap(student)
sortAseendingList = sortAseending(studentMap)
printStudent(studentMap, sortAseendingList)
