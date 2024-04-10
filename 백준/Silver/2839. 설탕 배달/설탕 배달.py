def solve(n):
  dp = [float('inf')] * (n + 1)
  dp[0] = 0

  for i in range(3, n + 1):
    dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1)

  return dp[n]

n = int(input())
result = solve(n)

if result == float('inf'):
  print(-1)
else:
  print(result)