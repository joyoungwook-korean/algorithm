nums = [int(input()) for _ in range(9)]
max = -1

for num in nums:
    if max < num:
        max = num

print(max)
print(nums.index(max)+1)