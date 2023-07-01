import sys

counts = int(sys.stdin.readline())
nums = [0]*10001

for i in range(counts):
    nums[int(sys.stdin.readline())] +=1

for i in range(len(nums)):
    if nums[i] != 0:
        for _ in range(nums[i]):
            sys.stdout.write(str(i) + '\n')
