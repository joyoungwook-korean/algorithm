# https://www.acmicpc.net/problem/10870

num = int(input())

memo = [-1] * (num + 1)


def fibonacci(n):
    global result
    if n <= 1:
        return n

    if memo[n] != -1:
        return memo[n]

    result = fibonacci(n - 1) + fibonacci(n - 2)

    memo[n] = result

    return result


print(fibonacci(num))
