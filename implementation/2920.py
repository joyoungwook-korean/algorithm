# 음계
# https://www.acmicpc.net/problem/2920

nums = list(map(int, input().split()))
def test():
    result = ''
    if nums[0] == 8:
        tmp = 8
        result = 'descending'
    else:
        tmp = 1
        result = 'ascending'
    
    for i in nums:
        if i != tmp:
             result = 'mixed'
        
        if nums[0] == 8:
            tmp -= 1
        else:
            tmp += 1

    return result          

print(test())
    
