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
n, m = map(int,input().split)

for i in range(1, n+1):
    for j in range(1, m+1):
        c = i + ' ' + j
        print(c)




