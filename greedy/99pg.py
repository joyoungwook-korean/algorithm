n,k = map(int, input().split())
result = 0
while n >= k:
    if n % k == 0:
        n = n/k
    else:
        n -= 1
    result +=1

while n != 1:
    n -= 1
    result +=1

print(result)