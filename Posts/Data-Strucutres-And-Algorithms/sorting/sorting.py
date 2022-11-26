def bubbleSort(arr: list) -> list:
    n = len(arr)
    for i in range(0, n):
        for j in range(0, n - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

    return arr

def insertionSort(arr: list) -> list:
    n = len(arr)
    for i in range(1, n):
        j = i
        while (j > 0 and arr[i] < arr[j - 1]):
            j -= 1
        
        tmp = arr[i]
        k = i
        while (k > j):
            arr[k] = arr[k - 1]
            k -= 1
        
        arr[j] = tmp
    
    return arr


def merge(arr: list, l: int, m: int, r: int):
	n1 = m - l + 1
	n2 = r - m

	# Copy data to temp arrays L[] and R[]
	L = []
	R = []

	for i in range(0, n1):
		L.append(arr[l + i])

	for j in range(0, n2):
		R.append(arr[m + 1 + j])

	# Merge the temp arrays back into arr[l..r]
	i = 0	 # Initial index of first subarray
	j = 0	 # Initial index of second subarray
	k = l	 # Initial index of merged subarray

	while i < n1 and j < n2:
		if L[i] <= R[j]:
			arr[k] = L[i]
			i += 1
		else:
			arr[k] = R[j]
			j += 1
		k += 1

	# Copy the remaining elements of L[], if there
	# are any
	while i < n1:
		arr[k] = L[i]
		i += 1
		k += 1

	# Copy the remaining elements of R[], if there
	# are any
	while j < n2:
		arr[k] = R[j]
		j += 1
		k += 1


def mergeSort(arr: list, l: int, r: int):
	if l < r:
		# Same as (l+r)//2, but avoids overflow for
		# large l and h
		m = l+(r-l)//2

		# Sort first and second halves
		mergeSort(arr, l, m)
		mergeSort(arr, m+1, r)
		merge(arr, l, m, r)


def quickSort(arr: list, left: int, right: int):
    i = left
    j = right
    pivot = arr[(right - left) // 2 + left]
    
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


def distributingSort(arr: list):
    f = [0 for i in range(0, 1000001)]
    
    for item in arr:
        f[item] += 1
    
    a = list()
    
    for i in range(0, 1000001):
        for j in range(0, f[i]):
            a.append(i)
    
    return a

a = [3, 2, 4, 1, 5, 9, 10, 8, 6]

# print(quickSort(a, 0, len(a) - 1))
print(distributingSort(a))

