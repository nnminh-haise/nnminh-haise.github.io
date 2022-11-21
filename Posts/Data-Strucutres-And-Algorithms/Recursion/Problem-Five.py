def sqr(n: int):
    n *= n
    return n

def main():
    n = 4
    print(n)
    n = sqr(n)
    print(n)


main()

# def backtracking(n: int, index: int, counter: int, x: list):
#     if (index == n):
#         print("".join(list(map(str, x))))
#         counter = counter + 1
#         return counter
#     else:
#         for i in range(0, 2):
#             x[index] = i
#             counter = backtracking(n, index + 1, counter, x)


# def main():
#     n = int(3)
#     counter = int(0)
#     x = [0 for i in range(0, n)]
    
#     counter = backtracking(n, 0, counter, x)    
#     print(counter)


# main()