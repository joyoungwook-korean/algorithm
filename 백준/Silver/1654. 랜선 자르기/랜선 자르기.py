import sys

K, N = map(int, sys.stdin.readline().split())
lanes = [int(sys.stdin.readline()) for _ in range(K)]

left, right = 1, max(lanes)

while left <= right:
    mid = (left + right) // 2
    total = sum([lane // mid for lane in lanes])
    
    if total >= N:
        left = mid + 1
    else:
        right = mid - 1

print(right)