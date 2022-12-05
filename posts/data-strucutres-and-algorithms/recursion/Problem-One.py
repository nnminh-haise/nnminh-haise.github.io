def a(i: int):
	if i == 0:
		return 1

	return a(i - 1) + 1


n = int(input())
s = 0
for i in range(0, n):
	s += a(i)

print(s)

