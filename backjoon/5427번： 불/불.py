#  **************************************************************************  #
#                                                                              #
#                                                       :::    :::    :::      #
#    Problem Number: 5427                              :+:    :+:      :+:     #
#                                                     +:+    +:+        +:+    #
#    By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+   #
#                                                   +#+      +#+        +#+    #
#    https://boj.kr/5427                           #+#        #+#      #+#     #
#    Solved: 2024/12/15 12:40:10 by siosio0915    ###          ###   ##.kr     #
#                                                                              #
#  **************************************************************************  #
from collections import deque


def bfs():
    global result
    global is_out
    while queue:
        nx, ny, target, count = queue.popleft()
        for dy, dx in direction:
            tx, ty = nx + dx, ny + dy
            if ty >= y or ty < 0 or tx >= x or tx < 0:
                continue

            if target == "fire":
                if table[ty][tx] != "#" and table[ty][tx] != "*":
                    table[ty][tx] = "*"
                    queue.append((tx, ty, "fire", 0))

            if target == "person":
                if table[ty][tx] == ".":
                    if tx == x - 1 or tx == 0 or ty == y - 1 or ty == 0:
                        is_out = True
                        result = count + 1
                        return
                    table[ty][tx] = "@"
                    queue.append((tx, ty, "person", count + 1))


num = int(input())
direction = [[1, 0], [0, 1], [-1, 0], [0, -1]]

for _ in range(num):
    x, y = map(int, input().split())
    now_location_x = 0
    now_location_y = 0
    queue = deque()
    table = []
    result = 1
    is_out = False

    for iy in range(y):
        row = list(input().strip())
        table.append(row)
        for ix in range(x):
            if row[ix] == "@":
                now_location_x = ix
                now_location_y = iy
                table[iy][ix] = 1
            if row[ix] == "*":
                queue.append((ix, iy, "fire", 0))

    if (
        now_location_x == 0
        or now_location_x == x - 1
        or now_location_y == 0
        or now_location_y == y - 1
    ):
        print(1)
        continue

    queue.append((now_location_x, now_location_y, "person", 1))
    bfs()

    if is_out:
        print(result)
    else:
        print("IMPOSSIBLE")
