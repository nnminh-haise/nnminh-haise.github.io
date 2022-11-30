def quickSort(arr: list, left: int, right: int) -> list:
    i = left
    j = right
    pivot = arr[(right - left + 1) // 2 + left]
    
    while (i <= j):
        while (arr[i] < pivot):
            i += 1
        
        while (arr[j] > pivot):
            j -= 1
        
        if (i <= j):
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1
    
    if (left < j):
        quickSort(arr, left, j)
    
    if (i < right):
        quickSort(arr, i, right)
    
    return arr


n, k = list(map(int, input().split(" ")))
a = list(map(int, input().split(" ")))

a = quickSort(a, 0, len(a) - 1)

print(a[k - 1])
