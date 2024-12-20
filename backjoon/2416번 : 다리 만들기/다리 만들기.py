#  **************************************************************************  #
#                                                                              #
#                                                       :::    :::    :::      #
#    Problem Number: 2416                              :+:    :+:      :+:     #
#                                                     +:+    +:+        +:+    #
#    By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+   #
#                                                   +#+      +#+        +#+    #
#    https://boj.kr/2416                           #+#        #+#      #+#     #
#    Solved: 2024/12/19 18:38:50 by siosio0915    ###          ###   ##.kr     #
#                                                                              #
#  **************************************************************************  #
from collections import deque


count = int(input())
original_table = [list(map(int, input().split())) for _ in range(count)]
original_visited = [[False for _ in range(count)] for _ in range(count)]
directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]
island_dic = {}
island_num = 0
result = 100000000


def island_num_bfs():
    ny, nx = island_num_queue.popleft()

    for dy, dx in directions:
        ty, tx = ny + dy, nx + dx

        if ty >= count or ty < 0 or tx >= count or tx < 0 or original_visited[ty][tx]:
            continue

        if original_table[ty][tx] == 0:
            edge_num_queue.append((ty, tx, ny, nx, 1))
        if original_table[ty][tx] == 1:
            original_visited[ty][tx] = True
            island_num_queue.append((ty, tx))


def result_bfs():
    ny, nx, _, _, reuslt_count = q.popleft()

    for dy, dx in directions:
        ty, tx = dy + ny, dx + nx
        if ty >= count or ty < 0 or tx >= count or tx < 0 or edge_num_visited[ty][tx]:
            continue
        if original_table[ty][tx] == 1:
            return reuslt_count

        if original_table[ty][tx] == 0:
            edge_num_visited[ty][tx] = True
            q.append((ty, tx, 0, 0, reuslt_count + 1))
    return None


for y in range(count):
    for x in range(count):
        if original_table[y][x] == 1 and not original_visited[y][x]:
            original_visited[y][x] = True
            edge_num_queue = deque()
            island_num_queue = deque()
            island_num_queue.append((y, x))
            while island_num_queue:
                island_num_bfs()
            island_dic[island_num] = edge_num_queue
            island_num += 1

for n in range(island_num - 1):
    q = deque()
    q = island_dic[n]
    edge_num_visited = [[False for _ in range(count)] for _ in range(count)]

    for y, x, ny, nx, c in island_dic[n]:
        edge_num_visited[y][x] = True
        edge_num_visited[ny][nx] = True

    while q:
        r = result_bfs()
        if r is not None and r < result:
            result = r
            break
print(result)
