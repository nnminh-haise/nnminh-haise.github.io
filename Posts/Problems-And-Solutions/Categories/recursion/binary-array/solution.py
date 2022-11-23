
def recursion(n: int, index: int, arr):
    if (index == n):
        print(" ".join(list(map(str, arr))))
    else:
        for i in range(0, 2):
            arr[index] = i
            recursion(n, index + 1, arr)


n = int(input())
arr = [0 for i in range(0, n)]

recursion(n, 0, arr)
