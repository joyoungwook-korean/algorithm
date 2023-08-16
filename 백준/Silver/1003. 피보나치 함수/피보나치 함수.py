# https://www.acmicpc.net/problem/25501
memo = {}


def fibonacci(n):
    if n == 0:
        return (1, 0)
    elif n == 1:
        return (0, 1)

    if n in memo:
        return memo[n]

    a, b = fibonacci(n - 1)
    c, d = fibonacci(n - 2)

    memo[n] = (a + c, b + d)
    return memo[n]


result = []

for _ in range(int(input())):
    n = int(input())
    zero, one = fibonacci(n)
    result.append((zero, one))

for zero, one in result:
    print(zero, one)
