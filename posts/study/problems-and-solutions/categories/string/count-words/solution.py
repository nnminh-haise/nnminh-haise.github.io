s = input()

ans = 0
index = 0

while index < len(s):
    tmp = ""
    while s[index] != ' ':
        tmp += s[index]
        index += 1
    index += 1
    if len(tmp) > 0:
        ans += 1

print(ans)
