
# Sắp xếp

***Bài toán mở đầu:*** Cho một dãy $A$ có $n \; (1 \le n \le 10^6)$ phần tử. Hãy sắp xếp lại mảng $A$ theo thứ tự tăng dần về giá trị của các phần tử.

***Dữ liệu vào:***

- Dòng đầu tiên là số nguyên dương $n$ - số lượng phần tử của dãy $A$.
- Dòng thứ hai là $n$ số nguyên dương $a_1, a_2, a_3, \ldots, a_n$ lần lượt là giá trị của các phần tử trong dãy $A$.

***Dữ liệu ra:***

- Một dòng duy nhất là mảng $A$ sau khi được sắp xếp.

---

## Thuật toán sắp xếp nổi bọt (Bubble Sort)

### Ý tưởng

- Xét hai cặp phần tử liên tiếp, nếu **phần tử đứng sau nhỏ hơn phần tử đứng trước** thì **đổi chỗ hai phần tử**. Nói cách khác, phần tử nào có giá trị nhỏ hơn thì sẽ nổi lên trên.
- Lặp lại quá trình trên cho đến khi không còn cặp phần tử nào thỏa mãn điều kiện trên.

### Ưu và nhược điểm

- Ưu điểm:
    
    - Thuật toán ngắn gọn, dễ hiểu, dễ nhớ.
    - Code ngắn gọn, dễ áp dụng.

- Nhược điểm:

    - Thuật toán không đủ nhanh đối với các tập dữ liệu lớn. Độ phức tạp thời gian $O(n^2)$.

### Cài đặt thuật toán

```py
def bubbleSort(arr: list) -> list:
    n = len(arr)
    for i in range(0, n):
        for j in range(0, n - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

    return arr
```

---

## Thuật toán sắp xếp chèn (Insrtion Sort)

### Ý tưởng

- Ý tưởng chỉnh của thuật toán là ta sẽ sắp xếp các đoạn có $1, 2, 3, \ldots, n$ phần tử đầu tiên.
- Giả sử, ta đã sắp xếp xong $i$ phần tử đầu tiên của mảng, ta cần tìm vị trí thích hợp cho phần tử thứ $i + 1$ và chèn nó vào.

### Ưu và nhược điểm

- Ưu điểm:

    - Thuật toán ngắn gọn, dễ hiểu, dễ nhớ.
    - Code ngắn gọn, dễ áp dụng.

- Nhược điểm:

    - Thuật toán không đủ nhanh đối với các tập dữ liệu lớn. Độ phức tạp thời gian $O(n^2)$.

### Cài đặt thuật toán

```py
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
```

---

## Thuật toán sắp xếp trộn (Merge Sort)

### Ý tưởng

Đây là thuật toán áp dụng kiến thức về đệ quy như sau:

- Chia dãy làm hai phần, sắp xếp từng phần.
- Sau khi sắp xếp xong từng phần ta sẽ thực hiện nối hai dãy lại như sau:

    - Tạo một dãy $B$ mới để chứa dãy sau khi nối.
    - So sánh phần tử đầu tiên của hai phần, đưa phần tử nhỏ hơn vào dãy $B$ mới và xóa khỏi phần tương ứng.
    - Lạp lại cho đến khi hết cả hai phần.

### Ưu và nhược điểm

- Ưu điểm:

    - Thuật toán có thời gian chạy nhanh với dộ phức tạp thuật toán là $O(n \log n)$.
    - Thuật toán có tính ổn định cao.

- Nhược điểm:

    - Cần dùng thêm bộ nhớ để lưu trữ mảng mới.

### Cài đặt thuật toán

```py
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
```

---

## Thuật toán sắp xếp nhanh (Quick Sort)

### Ý tưởng

- Chia dãy đã cho thành hai thành phần:

    - Chọn một khóa "**pivot**" (ngẫu nhiên hoặc chia đôi).
    - Những phần tử lớn hơn "**pivot**" đưa vào một bên.
    - Những phần tử bé hơn "**pivot**" đưa vào bên còn lại.

- Gọi đệ quy để sắp xếp hai phần.

### Ưu và nhược điểm

- Ưu điểm:
    
    - Thuật toán có thời gian chạy nhanh $O(n \log n)$.

- Nhược điểm:

    - Tùy thuộc vào cách chia "**pivot**" mà độ phức tạp thời gian sẽ bị ảnh hưởng. Nếu chia không tốt thì độ phức tạp thời gian có thể là $O(n^2)$ nhưng trường hợp đó rất hiếm gặp.
    - Không ổn định.

### Cài đặt thuật toán

```py
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
```

---

## Thuật toán sắp xếp đếm phân phối (Distributing Sort)

### Ý tưởng

- Đếm số lần xuất hiện của các giá trị trong dãy cần sắp xếp. Suy ra được tập các giá trị duy nhất.
- Sắp xếp tập các giá trị duy nhất.
- Dựa trên tập giá trị kết hợp với tần suất của mỗi giá trị để hoàn thành việc sắp xếp dãy.

### Ưu và nhược điểm

- Ưu điểm:

    - Có thời gian chạy tuyến tính nếu các giá trị sắp xếp không quá lớn.
    - Ổn định.

- Nhược điểm:

    - Không thích hợp khi sắp xếp các tập giá trị lớn.

### Cài đặt thuật toán

*Cài đặt dưới đây được áp dụng đối với việc sắp xếp tập giá trị là các số nguyên có giá trị trong đoạn $[1, 10^6]$*.

```py
def distributingSort(arr: list):
    f = [0 for i in range(0, 1000001)]
    
    for item in arr:
        f[item] += 1
    
    a = list()
    
    for i in range(0, 1000001):
        for j in range(0, f[i]):
            a.append(i)
    
    return a
```

---

## Tài liệu tham khảo

- [Tài liệu chuyên tin 1 | Sách, PDF](https://thuvienpdf.com/tai-lieu-chuyen-tin-hoc-quyen-1).
- [Các thuật toán sắp xếp | VNOI](https://vnoi.info/wiki/algo/basic/sorting.md).
- [Thuật toán sắp xếp nhanh | Programiz](https://www.programiz.com/dsa/quick-sort).
