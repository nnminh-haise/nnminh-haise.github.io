def lowerBound(a: list, target: int)->int:
    p = 10000007
    left, right = 0, len(a) - 1
    
    while left <= right:
        mid = (right - left + 1) // 2 + left
        if target <= a[mid]:
            p = min(p, mid)
            right = mid - 1
        else:
            left = mid + 1

    return p


print(lowerBound([1, 2, 2, 4, 5], 0))
