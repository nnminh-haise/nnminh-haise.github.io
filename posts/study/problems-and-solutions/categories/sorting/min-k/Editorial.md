
# Nhỏ thứ k | Editorial - Lời giải

> *Tags: Sorting*

## Statement - Đề bài

Cho một dãy gồm $n \; (1 \le n \le 10000)$ số nguyên dương $a_1, a_2, a_3, \ldots, a_n \; (1 \le a_i \le 10000)$ và số nguyên dương $k \; (k \le n)$.

***Yêu cầu:*** Tìm số nhỏ thứ $k$ trong dãy đã cho.

### Input - Dữ liệu vào

- Dòng đầu tiên gồm hai số nguyên dương $n, k$ lần lượt là số lượng phần tử của dãy và số nguyên dương $k$ như mô tả.
- Dòng thứ hai là $n$ số nguyên dương $a_1, a_2, a_3, \ldots, a_n$.

### Output - Dữ liệu ra

- Một số nguyên dương duy nhất là số nhỏ thứ $k$ trong dãy.

---

## Solution - Giải thuật

Sắp xếp lại dãy theo chiều tăng dần và in ra phần tử thứ $k$ của dãy đã sắp xếp.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int *a = new int [n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);

    cout << a[k - 1] << endl;

    return 0;
}
```

***Python:***

```py
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
```
