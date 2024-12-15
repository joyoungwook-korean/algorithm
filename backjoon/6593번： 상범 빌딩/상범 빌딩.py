#  **************************************************************************  #
#                                                                              #
#                                                       :::    :::    :::      #
#    Problem Number: 6593                              :+:    :+:      :+:     #
#                                                     +:+    +:+        +:+    #
#    By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+   #
#                                                   +#+      +#+        +#+    #
#    https://boj.kr/6593                           #+#        #+#      #+#     #
#    Solved: 2024/12/15 17:02:30 by siosio0915    ###          ###   ##.kr     #
#                                                                              #
#  **************************************************************************  #


def bfs():
    global is_out
    global min
    nz, ny, nx = queue.popleft()
    for dz, dy, dx in directions:
        tz, ty, tx = nz + dz, ny + dy, nx + dx

        if tz >= iz or tz < 0 or ty >= iy or ty < 0 or tx >= ix or tx < 0:
            continue
        if table[tz][ty][tx] == "E":
            min = table[nz][ny][nx] + 1
            is_out = True
            return
        if table[tz][ty][tx] != ".":
            continue
        queue.append((tz, ty, tx))
        table[tz][ty][tx] = table[nz][ny][nx] + 1


from collections import deque

directions = [[1, 0, 0], [0, 1, 0], [0, 0, 1], [-1, 0, 0], [0, -1, 0], [0, 0, -1]]
result = []


while True:
    iz, iy, ix = map(int, input().split())
    if iz == 0:
        break
    queue = deque()
    is_out = False
    table = []
    min = 0
    for z in range(iz):
        floor = []
        for y in range(iy):
            row = list(input().strip())
            floor.append(row)
            for x in range(ix):
                if row[x] == "S":
                    queue.append((z, y, x))
                    row[x] = 0

        table.append(floor)
        if z < iz - 1:
            input()
    while queue:
        if is_out:
            break
        bfs()

    if is_out:
        result.append("Escaped in %d minute(s)." % min)
    else:
        result.append("Trapped!")
    input()

for r in result:
    print(r)
