s = input()
p = input()

ans = 0

for i in range(0, len(s) - len(p) + 1):
    if s[i] == p[0]:
        flag = True
        for j in range(len(p)):
            if s[i + j] != p[j]:
                flag = False
                break
        if flag:
            ans += 1


print("no" if ans == 0 else "yes")
