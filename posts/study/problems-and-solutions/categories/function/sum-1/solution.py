def f(n: float)->float:
    res = 0
    for i in range(1, n + 1):
        res += 1 / i
    return res


print(round(f(int(input())), 3))
