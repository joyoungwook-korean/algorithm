# https://www.acmicpc.net/problem/11723
import sys

n = int(sys.stdin.readline())

mask = 0

for _ in range(n):
    check_string  = sys.stdin.readline().strip().split()
    startString = check_string[0]
    if startString == 'add':
        mask |= (1 << int(check_string[1]))
    elif startString == 'remove':
        mask &= ~(1 << int(check_string[1]))
    elif startString == 'check':
       if mask & (1 << int(check_string[1])):
           print(1)
       else:
           print(0)
    elif startString == 'toggle':
        mask ^= (1 << int(check_string[1]))
    elif startString == 'all':
        mask = (1 << 21) - 1
    else:
        mask = 0
