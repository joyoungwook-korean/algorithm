#  **************************************************************************  #
#                                                                              #
#                                                       :::    :::    :::      #
#    Problem Number: 1600                              :+:    :+:      :+:     #
#                                                     +:+    +:+        +:+    #
#    By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+   #
#                                                   +#+      +#+        +#+    #
#    https://boj.kr/1600                           #+#        #+#      #+#     #
#    Solved: 2024/12/20 14:36:11 by siosio0915    ###          ###   ##.kr     #
#                                                                              #
#  **************************************************************************  #

from collections import deque


def bfs():
    while queue:
        ny, nx, count, jump_count = queue.popleft()
        if ny == rows - 1 and nx == cols - 1:
            return count

        if jump_count + 1 <= jump_input:
            for jump_dy, jump_dx in directions_jump:
                jump_ty, jump_tx = jump_dy + ny, jump_dx + nx

                if jump_ty >= rows or jump_ty < 0 or jump_tx >= cols or jump_tx < 0:
                    continue
                if visited[jump_count + 1][jump_ty][jump_tx]:
                    continue
                if table[jump_ty][jump_tx] == 1:
                    continue

                visited[jump_count + 1][jump_ty][jump_tx] = True
                queue.append((jump_ty, jump_tx, count + 1, jump_count + 1))

        for dy, dx in directions_one:
            ty, tx = ny + dy, nx + dx

            if ty >= rows or ty < 0 or tx >= cols or tx < 0 or table[ty][tx] == 1:
                continue
            if visited[jump_count][ty][tx]:
                continue

            visited[jump_count][ty][tx] = True
            queue.append((ty, tx, count + 1, jump_count))
    return -1


directions_one = [[1, 0], [0, 1], [-1, 0], [0, -1]]
directions_jump = [
    [2, 1],
    [1, 2],
    [-2, 1],
    [1, -2],
    [-2, -1],
    [-1, -2],
    [-1, 2],
    [2, -1],
]
jump_input = int(input())
cols, rows = map(int, input().split())
queue = deque()
table = [list(map(int, input().split())) for _ in range(rows)]
visited = [[[False] * cols for _ in range(rows)] for _ in range(jump_input + 1)]
queue.append((0, 0, 0, 0))

print(bfs())
