def f(n: float) -> float:
    if n == 1:
        return 1
    
    return (1 / n + f(n - 1))


n = float(input())
print(f(n))
