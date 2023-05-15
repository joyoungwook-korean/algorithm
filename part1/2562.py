nums = list(map(int, input().split()))

maxNum = nums[0]
maxIndex = 0 

for idx, num in enumerate(nums):
    if maxNum <= num:
        maxNum = num
        maxIndex = idx

print(maxNum)
print(maxIndex+1)