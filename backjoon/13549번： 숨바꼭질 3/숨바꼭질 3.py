#  **************************************************************************  #
#                                                                              #
#                                                       :::    :::    :::      #
#    Problem Number: 13549                             :+:    :+:      :+:     #
#                                                     +:+    +:+        +:+    #
#    By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+   #
#                                                   +#+      +#+        +#+    #
#    https://boj.kr/13549                          #+#        #+#      #+#     #
#    Solved: 2024/12/20 13:54:15 by siosio0915    ###          ###   ##.kr     #
#                                                                              #
#  **************************************************************************  #
from collections import deque


def bfs():
    while queue:
        s, count = queue.popleft()
        if s == f:
            return count

        if s > 200000 or s < 0 or visited[s] <= count:
            continue
        visited[s] = count

        queue.appendleft((s * 2, count))
        queue.append((s + 1, count + 1))
        queue.append((s - 1, count + 1))

    return None


s, f = map(int, input().split())
queue = deque()
queue.append((s, 0))
visited = [float("inf")] * 200001

print(bfs())
