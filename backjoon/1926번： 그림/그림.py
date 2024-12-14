#  **************************************************************************  #
#                                                                              #
#                                                       :::    :::    :::      #
#    Problem Number: 1926                              :+:    :+:      :+:     #
#                                                     +:+    +:+        +:+    #
#    By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+   #
#                                                   +#+      +#+        +#+    #
#    https://boj.kr/1926                           #+#        #+#      #+#     #
#    Solved: 2024/12/14 15:34:10 by siosio0915    ###          ###   ##.kr     #
#                                                                              #
#  **************************************************************************  #
from collections import deque

def bfs(y, x):
    global max_area
    queue = deque()
    queue.append((y, x))
    visit[y][x] = True
    area = 1

    while queue:
        y, x = queue.popleft()
        for dy, dx in directions:
            ny, nx = y + dy, x + dx
            if ny >= rows or ny < 0 or nx >= cols or nx < 0:
                continue
            if visit[ny][nx]:
                continue
            if  table[ny][nx] == 0:
                continue
            area +=1
            visit[ny][nx] =True
            queue.append((ny,nx))
    
    if area > max_area:
        max_area = area
    return 1


total_area = 0
max_area = 0
rows, cols = map(int, input().split())
directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

table = [list(map(int, input().split())) for _ in range(rows)]
visit = [[False for _ in range(cols)] for _ in range(rows)]

for y in range(rows):
    for x in range(cols):
        if visit[y][x] == True or table[y][x] == 0:
            continue
        total_area += bfs(y,x)
        


print(total_area)
print(max_area)