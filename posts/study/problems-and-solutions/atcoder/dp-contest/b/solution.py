n, k = [int(_) for _ in input().strip().split()]
a = [int(_) for _ in input().strip().split()]

dp = [10**9 for _ in range(n)]

dp[0] = 0
for i in range(0, n):
    for j in range(1, k + 1):
        if i + j < n:
            dp[i + j] = min(dp[i + j], dp[i] + abs(a[i] - a[i + j]))

print(dp[n - 1])
