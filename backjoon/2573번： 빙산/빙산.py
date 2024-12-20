#  **************************************************************************  #
#                                                                              #
#                                                       :::    :::    :::      #
#    Problem Number: 2573                              :+:    :+:      :+:     #
#                                                     +:+    +:+        +:+    #
#    By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+   #
#                                                   +#+      +#+        +#+    #
#    https://boj.kr/2573                           #+#        #+#      #+#     #
#    Solved: 2024/12/19 13:03:17 by siosio0915    ###          ###   ##.kr     #
#                                                                              #
#  **************************************************************************  #
from collections import deque
import copy


def is_out():
    check_visited = [[False] * cols for _ in range(rows)]
    check_queue = deque()
    result = 0
    for y in range(rows):
        for x in range(cols):
            if table[y][x] == 0 or check_visited[y][x]:
                continue

            check_queue.append((y, x))
            check_visited[y][x] = True

            while check_queue:
                ny, nx = check_queue.popleft()
                for dy, dx in directions:
                    ty, tx = dy + ny, dx + nx
                    if (
                        ty >= rows
                        or ty < 0
                        or tx >= cols
                        or tx < 0
                        or check_visited[ty][tx]
                        or table[ty][tx] == 0
                    ):
                        continue

                    check_visited[ty][tx] = True
                    check_queue.append((ty, tx))
            result += 1
    return result >= 2


def bfs(visited):
    global queue
    global table
    next_queue = deque()

    while queue:
        ny, nx = queue.popleft()
        visited[ny][nx] = True
        water_count = 0

        for dy, dx in directions:
            ty, tx = ny + dy, nx + dx

            if ty >= rows or ty < 0 or tx >= cols or tx < 0 or visited[ty][tx]:
                continue

            if not visited[ty][tx] and table[ty][tx] == 0:
                water_count += 1
            if not visited[ty][tx] and table[ty][tx] != 0:
                visited[ty][tx] = True
        table[ny][nx] = max(0, table[ny][nx] - water_count)
        if table[ny][nx] != 0:
            next_queue.append((ny, nx))

    queue = next_queue


rows, cols = map(int, input().split())
table = []
queue = deque()
directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]

for y in range(rows):
    row = list(map(int, input().split()))
    table.append(row)
    for x in range(cols):
        if table[y][x] != 0:
            queue.append((y, x))

if not queue:
    print(0)
    exit(0)
if is_out():
    print(0)
    exit(0)

count = 0
while queue:
    count += 1
    visited = [[False] * cols for _ in range(rows)]
    bfs(visited)
    if is_out():
        print(count)
        exit(0)
print(0)
