#  **************************************************************************  #
#                                                                              #
#                                                       :::    :::    :::      #
#    Problem Number: 16933                             :+:    :+:      :+:     #
#                                                     +:+    +:+        +:+    #
#    By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+   #
#                                                   +#+      +#+        +#+    #
#    https://boj.kr/16933                          #+#        #+#      #+#     #
#    Solved: 2024/12/21 12:55:49 by siosio0915    ###          ###   ##.kr     #
#                                                                              #
#  **************************************************************************  #
from collections import deque
import sys


rows, cols, k = map(int, sys.stdin.readline().split())
directions = [[-1, 0], [0, -1], [1, 0], [0, 1]]
visited = [[[False for _ in range(cols)] for _ in range(rows)] for _ in range(k + 1)]
table = [list(map(int, sys.stdin.readline().strip())) for _ in range(rows)]
queue = deque()
visited[0][0][0] = True
queue.append((0, 0, 1, 0, 0))

while queue:
    ny, nx, count, broken, day_or_night = queue.popleft()
    if ny == rows - 1 and nx == cols - 1:
        print(count)
        sys.exit(0)
    next_day_or_night = 1 - day_or_night

    for dy, dx in directions:
        ty, tx = ny + dy, nx + dx

        if ty < 0 or ty >= rows or tx < 0 or tx >= cols:
            continue

        if not visited[broken][ty][tx] and table[ty][tx] == 0:
            visited[broken][ty][tx] = True
            queue.append((ty, tx, count + 1, broken, next_day_or_night))

        elif broken < k and table[ty][tx] == 1 and not visited[broken + 1][ty][tx]:
            if day_or_night == 0:
                visited[broken + 1][ty][tx] = True
                queue.append((ty, tx, count + 1, broken + 1, next_day_or_night))
            else:
                queue.append((ny, nx, count + 1, broken, next_day_or_night))


print(-1)
