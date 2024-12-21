#  **************************************************************************  #
#                                                                              #
#                                                       :::    :::    :::      #
#    Problem Number: 14442                             :+:    :+:      :+:     #
#                                                     +:+    +:+        +:+    #
#    By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+   #
#                                                   +#+      +#+        +#+    #
#    https://boj.kr/14442                          #+#        #+#      #+#     #
#    Solved: 2024/12/21 11:24:56 by siosio0915    ###          ###   ##.kr     #
#                                                                              #
#  **************************************************************************  #

from collections import deque


def bfs():
    while queue:
        ny, nx, count, broken = queue.popleft()
        if ny == rows - 1 and nx == cols - 1:
            return count

        for dy, dx in directions:
            ty, tx = dy + ny, dx + nx

            if ty >= rows or ty < 0 or tx >= cols or tx < 0:
                continue
            if broken < k and table[ty][tx] == 1 and not visited[ty][tx][broken + 1]:
                visited[ty][tx][broken + 1] = True
                queue.append((ty, tx, count + 1, broken + 1))
            if table[ty][tx] == 0 and not visited[ty][tx][broken]:
                visited[ty][tx][broken] = True
                queue.append((ty, tx, count + 1, broken))
    return -1


rows, cols, k = map(int, input().split())
visited = [[[False for _ in range(k + 1)] for _ in range(cols)] for _ in range(rows)]
table = [list(map(int, input().strip())) for _ in range(rows)]
directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]
visited[0][0][0] = True
queue = deque()
queue.append((0, 0, 1, 0))

print(bfs())
