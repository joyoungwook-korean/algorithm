import sys

input = sys.stdin.readline

directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]
cnt = 1


def light_on(ny, nx):
    global cnt
    for ty, tx in arr[ny][nx]:
        if not on[ty][tx]:
            on[ty][tx] = True
            cnt += 1

            for dy, dx in directions:
                y, x = ty + dy, tx + dx
                if y >= N or y < 0 or x >= N or x < 0:
                    continue
                if visit[y][x]:
                    visit[ty][tx] = True
                    queue.append((ty, tx))
                    break


N, M = map(int, input().split())

visit = [[False] * N for _ in range(N)]
on = [[False] * N for _ in range(N)]
arr = [[[] for _ in range(N)] for _ in range(N)]

for i in range(M):
    start_y, start_x, ty, tx = map(int, input().split())
    arr[start_y - 1][start_x - 1].append((ty - 1, tx - 1))


queue = [(0, 0)]
visit[0][0] = True
on[0][0] = True


while queue:
    ny, nx = queue.pop(0)
    light_on(ny, nx)

    for dy, dx in directions:
        y, x = dy + ny, dx + nx
        if y >= N or y < 0 or x >= N or x < 0:
            continue
        if not on[y][x]:
            continue
        if visit[y][x]:
            continue
        queue.append((y, x))
        visit[y][x] = True


print(cnt)
