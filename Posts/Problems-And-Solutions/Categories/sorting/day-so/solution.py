n, k = list(map(int, input().split(' ')))

f = [0 for i in range(0, n + 1)]
g = [0 for i in range(0, 128)]
f[1] = f[2] = 1
g[1] = 2

for i in range(3, n + 1):
    f[i] = (f[i - 1] + f[i - 2]) % 128
    g[f[i]] += 1

count = 0
p = 0
for i in range(0, 128):
    count += g[i]
    if (count >= k):
        p = i
        break

print(p)
