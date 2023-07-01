# 팰린드롬수
# https://www.acmicpc.net/problem/1259

def is_palindrome(nums):
    for i in range(len(nums)//2):
        if nums[i] != nums[-i-1]:
            return False
    return True

while True:
    nums = input()
    if nums == '0':
        break
    if is_palindrome(nums):
        print('yes')
    else:
        print('no')
