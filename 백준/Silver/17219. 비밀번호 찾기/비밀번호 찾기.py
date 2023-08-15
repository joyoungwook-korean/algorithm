# https://www.acmicpc.net/problem/17219

import sys
set_count, find_count = map(int, sys.stdin.readline().strip().split())

url_pwd_map = {}
for _ in range(set_count):
    url,pwd = map(str, sys.stdin.readline().strip().split(' '))
    url_pwd_map[url] = pwd
for _ in range(find_count):
    print(url_pwd_map[sys.stdin.readline().strip()])