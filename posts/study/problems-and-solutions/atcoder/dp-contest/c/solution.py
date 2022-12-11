n = int(input())
a = list()
for _ in range(n):
    a.append([int(_) for _ in input().strip().split()])

dp = [[0 for _ in range(3)] for _ in range(n)]
for i in range(3):
    dp[0][i] = a[0][i]

for i in range(1, n):
    dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i][0]
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + a[i][1]
    dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + a[i][2]

print(max(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]))
