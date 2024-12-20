#  **************************************************************************  #
#                                                                              #
#                                                       :::    :::    :::      #
#    Problem Number: 13913                             :+:    :+:      :+:     #
#                                                     +:+    +:+        +:+    #
#    By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+   #
#                                                   +#+      +#+        +#+    #
#    https://boj.kr/13913                          #+#        #+#      #+#     #
#    Solved: 2024/12/20 16:22:00 by siosio0915    ###          ###   ##.kr     #
#                                                                              #
#  **************************************************************************  #

from collections import deque


def bfs():
    while queue:
        now, before = queue.popleft()
        if now == f:
            result = []
            result.append(now)
            while before != -1:
                result.append(before)
                before = visited[before][1]
            return result[::-1]

        if now >= 200001 or now < 0 or visited[now][0] == True:
            continue
        visited[now][0] = True
        visited[now][1] = before
        queue.append((now + 1, now))
        queue.append((now - 1, now))
        queue.append((now * 2, now))


s, f = map(int, input().split())
visited = [[False, -1] for _ in range(200001)]
queue = deque()
queue.append((s, -1))

result = bfs()
print(len(result) - 1)
for i in result:
    print(i, end=" ")
