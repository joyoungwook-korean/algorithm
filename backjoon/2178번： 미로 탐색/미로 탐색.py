#  **************************************************************************  #
#                                                                              #
#                                                       :::    :::    :::      #
#    Problem Number: 2178                              :+:    :+:      :+:     #
#                                                     +:+    +:+        +:+    #
#    By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+   #
#                                                   +#+      +#+        +#+    #
#    https://boj.kr/2178                           #+#        #+#      #+#     #
#    Solved: 2024/12/14 17:10:05 by siosio0915    ###          ###   ##.kr     #
#                                                                              #
#  **************************************************************************  #

from collections import deque

def bfs():
    queue = deque()
    result = 0
    queue.append((0,0))

    while queue:
        ny, nx = queue.popleft()
        for dy, dx in direction:
            y, x = ny + dy, nx + dx
            if y >= rows or y < 0 or x >= cols or x < 0:
                continue
            if table[y][x] == 1:
                table[y][x] = table[ny][nx] + 1
                queue.append((y,x))
            if y == rows - 1 and x == cols - 1:
                return table[y][x]


rows, cols = map(int, input().split())
table = [list(map(int, input().strip())) for _ in range(rows)]
visit_count = [[1 for _ in range(cols)] for _ in range(rows)]
direction = [[1,0], [0,1], [-1,0], [0,-1]]
print(bfs())