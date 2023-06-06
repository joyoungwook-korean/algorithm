# 6072
"""num = int(input())

while num != 0:
    print(num)
    num = num-1"""

#6074
"""c = ord(input())
startChr = ord('a')
while startChr <=c:
    print(chr(startChr),end=' ')
    startChr += 1"""

#6075
"""num = int(input())
startNum = 0

while startNum != num+1:
    print(startNum)
    startNum += 1
"""

#6077
"""num = int(input())
result = 0

for i in range(1, num+1):
    if i % 2 == 0:
        result += i

print(result)"""

#6078
"""while True:
    c = input()
    print(c)
    if c == 'q':
        break"""

#6079
"""inputNum = int(input())
tempNum = 1
total = 0

while True:
    total += tempNum
    if total >= inputNum:
        print(tempNum)
        break
    tempNum += 1"""

#6080
'''n, m = map(int, input().split())

for i in range(1, n+1):
    for j in range(1, m+1):
        print(f"{i} {j}")'''

#6082
'''n = int(input())

for i in range(1, n+1):
    if i%10==3 or i%10==6 or i%10==9:
        print('X',end=' ')
    else:
        print(i,end=' ')'''

#6083
'''r, g, b = map(int, input().split())
cnt=0

for rgb_r in range(0, r):
    for rgb_g in range(0, g):
        for rgb_b in range(0, b):
            print(f"{rgb_r} {rgb_g} {rgb_b}")
            cnt += 1

print(cnt)'''

#6084
hz, bit, ch, s = map(int, input().split())

mb = 8*1024*1024
result = round(hz*bit*ch*s/mb, 1)
print(result, end=" MB")





