def missingNumber(a: list)->int:
    left, right = 0, len(a)
    while left < right:
        mid = (right - left) // 2 + left
        if mid < a[mid]:
            right = mid
        else:
            left = mid + 1
    
    return left

n = int(input())
print(missingNumber(list(map(int, input().split(' ')))))
