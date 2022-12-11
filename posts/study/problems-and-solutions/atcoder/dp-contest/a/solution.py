n = int(input())
a = [int(x) for x in input().strip().split()]
f = [0 for i in range(n)]

f[0] = 0;
f[1] = abs(a[1] - a[0]);
for i in range(2, n):
    f[i] = min(f[i - 1] + abs(a[i - 1] - a[i]),
               f[i - 2] + abs(a[i - 2] - a[i]))

print(f[n - 1])
