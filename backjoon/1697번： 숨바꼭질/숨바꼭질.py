#  **************************************************************************  #
#                                                                              #
#                                                       :::    :::    :::      #
#    Problem Number: 1697                              :+:    :+:      :+:     #
#                                                     +:+    +:+        +:+    #
#    By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+   #
#                                                   +#+      +#+        +#+    #
#    https://boj.kr/1697                           #+#        #+#      #+#     #
#    Solved: 2024/12/15 16:29:15 by siosio0915    ###          ###   ##.kr     #
#                                                                              #
#  **************************************************************************  #
from collections import deque


def bfs():
    queue = deque()
    queue.append((s, 0))
    visited = [False] * 200001
    visited[s] = True

    while queue:
        move, move_count = queue.popleft()
        if move == f:
            print(move_count)
            return
        for next_move in (move - 1, move + 1, move * 2):
            if 0 <= next_move <= 200000 and not visited[next_move]:
                visited[next_move] = True
                queue.append((next_move, move_count + 1))


s, f = map(int, input().split())
bfs()
