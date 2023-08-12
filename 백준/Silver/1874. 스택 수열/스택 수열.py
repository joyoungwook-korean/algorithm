# https://www.acmicpc.net/problem/1874

n = int(input())

top = 0
result = ''
pre = 0
tmp = 0
tmp_arr = []
def push(i):
    tmp_arr.append(i)
def pop():
    return tmp_arr.pop()
    
for _ in range(n):
    num = int(input())
    if num > tmp:
        if top != 0:
            result += '+'
            push(top)
            tmp = top
        for i in range(tmp+1, num+1):
            result += '+'
            push(i)
        result += '-'
        tmp = pop()
        top = num + 1
    else:
        while True:
            if len(tmp_arr) == 0:
                result = 'NO'
                break
            elif pop() == num:
                result += '-'
                break
if result.startswith('NO'):
    print('NO')
else:
    print('\n'.join(result))
    