#  **************************************************************************  #
#                                                                              #
#                                                       :::    :::    :::      #
#    Problem Number: 2206                              :+:    :+:      :+:     #
#                                                     +:+    +:+        +:+    #
#    By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+   #
#                                                   +#+      +#+        +#+    #
#    https://boj.kr/2206                           #+#        #+#      #+#     #
#    Solved: 2024/12/17 16:32:01 by siosio0915    ###          ###   ##.kr     #
#                                                                              #
#  **************************************************************************  #
from collections import deque


def bfs():
    ny, nx, is_broken, distance = queue.popleft()

    if ny == rows - 1 and nx == cols - 1:
        return True, distance
    for dy, dx in directions:
        ty, tx = ny + dy, nx + dx

        if ty >= rows or ty < 0 or tx >= cols or tx < 0:
            continue

        if table[ty][tx] == 1 and not is_broken:
            visited[ty][tx][1] = 1
            queue.append((ty, tx, 1, distance + 1))
        elif table[ty][tx] == 0 and not visited[ty][tx][is_broken]:
            visited[ty][tx][is_broken] = 1
            queue.append((ty, tx, is_broken, distance + 1))

    return False, -1


rows, cols = map(int, input().split())
directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]

table = [list(map(int, input().strip())) for _ in range(rows)]
visited = [[[0] * 2 for _ in range(cols)] for _ in range(rows)]
queue = deque()
visited[0][0][0] = 1
queue.append((0, 0, 0, 1))

while queue:
    is_out, result = bfs()
    if is_out:
        print(result)
        exit()
print(-1)
