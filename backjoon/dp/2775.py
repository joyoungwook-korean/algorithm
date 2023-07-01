# 부녀회장이 될테야
# https://www.acmicpc.net/problem/2775


n = int(input())

def solution(floor, ho):
    tmp_list = []
    tmp = [i for i in range(1,ho+1)]
    result=0
    for h in range(floor):
        for w in range(ho):
            tmp_list.append(sum(tmp[:w+1]))
        tmp = tmp_list.copy()
        result = tmp_list.pop()
        tmp_list.clear()
    print(result)


for _ in range(n):
    floor = int(input())
    w = int(input())
    solution(floor, w)

    