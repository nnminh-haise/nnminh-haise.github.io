n, k = list(map(int, input().split(' ')))
a = list(map(int, input().split(' ')))

ans = -1
for i in range(len(a)):
    if a[i] == k:
        ans = i
        break

print(ans)
