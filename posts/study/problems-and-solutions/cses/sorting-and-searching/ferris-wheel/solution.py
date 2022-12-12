n, x = [int(_) for _ in input().strip().split()]
a = [int(_) for _ in input().strip().split()]

a = sorted(a)

ans = i = 0
j = n - 1
used = [False for _ in range(n)]

while i < j:
    if a[i] + a[j] <= x:
        used[i] = used[j] = True
        i += 1
        j -= 1
        ans += 1
    else:
        j -= 1
for item in used:
    ans += (item == False)

print(ans)
