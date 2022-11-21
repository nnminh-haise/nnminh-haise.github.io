def backtracking(n: int, index: int, x: list):
	if index == n:
		print("".join(map(str, x)))
	else:
		for i in range(0, 2):
			x[index] = i
			backtracking(n, index + 1, x)


n = int(input())
x = [0 for i in range(0, n)]
backtracking(n, 0, x)

