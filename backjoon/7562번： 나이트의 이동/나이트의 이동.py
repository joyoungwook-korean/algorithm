#  **************************************************************************  #
#                                                                              #
#                                                       :::    :::    :::      #
#    Problem Number: 7562                              :+:    :+:      :+:     #
#                                                     +:+    +:+        +:+    #
#    By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+   #
#                                                   +#+      +#+        +#+    #
#    https://boj.kr/7562                           #+#        #+#      #+#     #
#    Solved: 2024/12/15 11:40:16 by siosio0915    ###          ###   ##.kr     #
#                                                                              #
#  **************************************************************************  #

from collections import deque


def bfs():
    while queue:
        nx, ny = queue.popleft()
        for dx, dy in direction:
            x, y = dx + nx, dy + ny
            if y >= line or y < 0 or x >= line or x < 0:
                continue
            if table[x][y] != -1:
                continue
            if x == gx and y == gy:
                return table[nx][ny] + 1
            queue.append((x, y))
            table[x][y] = table[nx][ny] + 1
    return -1


num = int(input())
direction = [[2, 1], [1, 2], [2, -1], [-1, 2], [-2, 1], [1, -2], [-2, -1], [-1, -2]]
for _ in range(num):
    line = int(input())
    x, y = map(int, input().split())
    gx, gy = map(int, input().split())
    if x == gx and y == gy:
        print(0)
        continue

    table = [[-1 for _ in range(line)] for _ in range(line)]
    queue = deque()
    table[x][y] = 0
    queue.append((x, y))
    print(bfs())
