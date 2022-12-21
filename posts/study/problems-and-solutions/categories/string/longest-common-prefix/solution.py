s = input()
p = input()

i = 0

while i < min(len(s), len(p)) and s[i] == p[i]:
    i += 1

print(i)
