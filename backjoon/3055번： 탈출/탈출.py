#  **************************************************************************  #
#                                                                              #
#                                                       :::    :::    :::      #
#    Problem Number: 3055                              :+:    :+:      :+:     #
#                                                     +:+    +:+        +:+    #
#    By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+   #
#                                                   +#+      +#+        +#+    #
#    https://boj.kr/3055                           #+#        #+#      #+#     #
#    Solved: 2024/12/15 21:58:26 by siosio0915    ###          ###   ##.kr     #
#                                                                              #
#  **************************************************************************  #


def dfs():
    ny, nx, w = queue.popleft()
    for dy, dx in directions:
        ty, tx = dy + ny, dx + nx

        if ty >= rows or ty < 0 or tx >= cols or tx < 0:
            continue

        if w == "water" and table[ty][tx] == ".":
            table[ty][tx] = "*"
            queue.append((ty, tx, "water"))
        if w == "hedgehog":
            if table[ty][tx] == "D":
                return True, table[ny][nx] + 1
            if table[ty][tx] == ".":
                table[ty][tx] = table[ny][nx] + 1
                queue.append((ty, tx, "hedgehog"))
    return False, None


from collections import deque

rows, cols = map(int, input().split())
directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]
queue = deque()
start_y = 0
start_x = 0
table = []

for y in range(rows):
    row = list(input().strip())
    table.append(row)
    for x in range(cols):
        if row[x] == "S":
            row[x] = 0
            start_x = x
            start_y = y
        if row[x] == "*":
            queue.append((y, x, "water"))

queue.append((start_y, start_x, "hedgehog"))
while queue:
    is_out, result = dfs()
    if is_out:
        print(result)
        exit()
print("KAKTUS")
