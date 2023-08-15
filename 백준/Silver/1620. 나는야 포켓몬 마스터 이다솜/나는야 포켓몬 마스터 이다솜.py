# https://www.acmicpc.net/problem/1620

import sys

map_num, print_num = sys.stdin.readline().strip().split()

pokemon_map = {}
pockmon_list = []

for i in range(1, int(map_num) +1):
    pockmon = sys.stdin.readline().strip()
    pokemon_map[pockmon] = i
    pockmon_list.append(pockmon)

for _ in range(int(print_num)):
    n = sys.stdin.readline().strip()
    if n in pokemon_map:
        print(pokemon_map[n])
    else:
        print(pockmon_list[int(n)-1])