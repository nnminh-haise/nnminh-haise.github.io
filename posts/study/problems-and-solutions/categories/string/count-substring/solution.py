s = input()
p = input()
ans = 0

for i in range(0, len(s) - len(p) + 1):
    flag = True
    for j in range(0, len(p)):
        if s[i + j] != p[j]:
            flag = False
    if flag:
        ans += 1

print(ans)
