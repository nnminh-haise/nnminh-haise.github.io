s = input()
n = len(s) - 1
flag = True

for i in range(0, n + 1):
    if s[i] != s[n - i]:
        flag = False
        break

print("yes" if flag else "no")
