# ACM 호텔
# https://www.acmicpc.net/problem/10250

n = int(input())
result = []


def getRoomNum():
    h,w,count = map(int,input().split())
    tmp = 0

    for i in range(1,w+1):
        for j in range(1,h+1):
            tmp += 1
            if count == tmp:
                if i < 10:
                    print(str(j)+str(0)+str(i))
                else:
                    print(str(j)+str(i))
               


for i in range(n):
    getRoomNum()
