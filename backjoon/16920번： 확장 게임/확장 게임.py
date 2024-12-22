import sys
from collections import deque

input = sys.stdin.readline


def solve():
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    N, M, P = map(int, input().split())
    speeds = list(map(int, input().split()))

    board = []
    queues = [deque() for _ in range(P)]
    result = [0] * P

    for r in range(N):
        row_str = input().rstrip()
        row = []
        for c in range(M):
            ch = row_str[c]
            if ch == "#":
                row.append(-1)
            elif ch == ".":
                row.append(0)
            else:
                pnum = int(ch)
                row.append(pnum)
                queues[pnum - 1].append((r, c))
                result[pnum - 1] += 1
        board.append(row)

    while True:
        expanded_any = False

        for pid in range(P):
            s = speeds[pid]
            if not queues[pid]:
                continue

            new_frontier = deque()
            current_queue = queues[pid]
            for _ in range(s):
                if not current_queue:
                    break

                next_queue = deque()

                while current_queue:
                    y, x = current_queue.popleft()

                    for dy, dx in directions:
                        ny, nx = y + dy, x + dx
                        if 0 <= ny < N and 0 <= nx < M:
                            if board[ny][nx] == 0:
                                board[ny][nx] = pid + 1
                                result[pid] += 1
                                expanded_any = True
                                next_queue.append((ny, nx))
                current_queue = next_queue

            new_frontier = current_queue
            queues[pid] = new_frontier

        if not expanded_any:
            break

    print(" ".join(map(str, result)))


if __name__ == "__main__":
    solve()
