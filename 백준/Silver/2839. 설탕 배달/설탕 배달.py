def solve(n):

    result = 0
    if n == 0:
        return -1
    while n >= 0:
        if n % 5 == 0:
            result += n / 5
            return result
        n -= 3
        result += 1

    return -1


n = int(input())
print(int(solve(n)))
