n, m ,k = map(int, input().split())
nums = list(map(int, input().split()))

nums.sort()
first = nums[n-1]
second = nums[n-2]

result = 0

for num in range(1,m+1):
    if num % k ==0:
        result += second
    else:
        result += first
    


print(result)