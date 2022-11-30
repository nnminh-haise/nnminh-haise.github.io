def quickSort(arr: list, left: int, right: int) -> list:
    i, j = left, right
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


def countDistinctValues(arr: list):
    result = 1
    
    for i in range(1, len(arr)):
        if (arr[i - 1] != arr[i]):
            result += 1
    
    return result


def highestFrequency(arr: list):
    result = -1
    count = 0
    
    for i in range(1, len(arr)):
        if (arr[i - 1] != arr[i]):
            count = 1
        else:
            count += 1
        
        if (count > result):
            result = count
    
    return result



n = int(input())
a = list(map(int, input().split(' ')))

a = quickSort(a, 0, len(a) - 1)
print(countDistinctValues(a))
print(highestFrequency(a))
