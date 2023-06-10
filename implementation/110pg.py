# 여행가 A는 NxN 크기의 정사각형 공간에 서 있고, 이 공간은 1 x 1 크기의 정사각형으로 나누어져 있다.
# 가장 왼쪽 위 좌표는 (1, 1)이고 가장 오른쪽 아래 좌표는 (N, N)이다.
# 상하좌우로 이동할 수 있으며, 시작 좌표는 (1,1)이다.

# 계획서대로 이동하면 되는데
# L, R, U, D는 각각 왼쪽, 오른쪽, 위, 아래로 한칸씩 이동하라는 뜻이다.

# 만약 공간을 벗어나는 움직임이 있다면 그 움직임은 무시하고 다음으로 넘어간다.

num  = int(input())
str_list = list(input().split())
result = [1,1]
cnt =0
while cnt != len(str_list):
    if str_list[cnt] == 'R':
        if result[1] !=num:
            result[1] += 1
    elif str_list[cnt] == 'U':
        if result[0] != 1:
            result[0] -=1
    elif str_list[cnt] == 'D':
        if result[0] != num:
            result[0] +=1
    elif str_list[cnt] == 'L':
        if result[1] != 1:
            result[1] -=1
    cnt +=1

print(result[0] ,result[1])
      
