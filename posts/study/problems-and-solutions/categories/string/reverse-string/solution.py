s = input()
res = ""

for i in range(len(s) - 1, -1, -1):
    res += s[i]

print(res)
