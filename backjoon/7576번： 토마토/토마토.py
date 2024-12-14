#  **************************************************************************  #
#                                                                              #
#                                                       :::    :::    :::      #
#    Problem Number: 7576                              :+:    :+:      :+:     #
#                                                     +:+    +:+        +:+    #
#    By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+   #
#                                                   +#+      +#+        +#+    #
#    https://boj.kr/7576                           #+#        #+#      #+#     #
#    Solved: 2024/12/14 18:49:24 by siosio0915    ###          ###   ##.kr     #
#                                                                              #
#  **************************************************************************  #

from collections import deque

def bfs():
    while queue:
        ny, nx = queue.popleft()
        for dy,dx in directions:
            y = ny + dy
            x = nx + dx
            if y >= rows or x >= cols or y< 0 or x < 0:
                continue
            if table[y][x] != 0:
                continue
            table[y][x] = table[ny][nx] + 1
            queue.append((y,x))

def result():
    result = 0
    for y in range(rows):
        for x in range(cols):
             if table[y][x] == 0:
                  return -1
             if result < table[y][x]:
                 result = table[y][x]
    if result == 1:
        return 0
    else:
        return result -1

cols,rows = map(int, input().split())
table = [list(map(int, input().split())) for _ in range(rows)]
queue = deque()
directions = [[1,0], [0,1],[-1,0],[0,-1]]

for y in range(rows):
    for x in range(cols):
        if table[y][x] == 1:
            queue.append((y,x))

bfs()
print(result())
