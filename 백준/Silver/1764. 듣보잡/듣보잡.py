# https://www.acmicpc.net/problem/1764

import sys

n, m = map(int, sys.stdin.readline().strip().split())
see_map = {}
result = []

for _ in range(n):
    see_map[sys.stdin.readline().strip()] = 0

for _ in range(m):
    heard_people = sys.stdin.readline().strip()
    if heard_people in see_map:
        result.append(heard_people)

print(len(result))
for r in sorted(result):
    print(r)