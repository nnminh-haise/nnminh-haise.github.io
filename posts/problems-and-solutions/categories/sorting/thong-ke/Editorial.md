
# Thống kê | Editorial - Lời giải

> *Tags: Sorting*

## Statement - Đề bài

Cho một dãy có $n \; (1 \le n \le 10^5)$ số nguyên dương $a_1, a_2, a_3, \ldots, a_n \; (1 \le a_i \le 10^5)$.

***Yêu cầu:*** Đếm số lượng phần tử có giá trị khác nhau trong dãy và đưa ra số lần lặp lại của phần tử xuất hiện nhiều nhất.

### Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $n$.
- Dòng thứ hai gồm $n$ số nguyên dương $a_1, a_2, a_3, \ldots, a_n$.

### Output - Dữ liệu ra

- Dòng đầu tiên là số nguyên dương $p$ là số lượng phần tử có giá trị khác nhau trong dãy đã cho.
- Dòng thứ hai là số nguyên dương $q$ là số lần lặp của phần tử xuất hiện nhiều nhất dãy.

---

## Solution - Giải thuật

Sắp xếp dãy cho trước. Sau khi dãy đã sắp xếp, có thể sử dụng một vòng lặp `for` để đếm số phần tử khác nhau trong dãy và xác định số lần lặp của phần tử lặp lại nhiều nhất.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int countDistinctValues(vector < int > arr) {
    int res = 1;

    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] != arr[i]) {
            ++res;
        }
    }

    return res;
}

int highestFrequency(vector < int > arr) {
    int res = -1;
    int count = 0;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] != arr[i]) {
            count = 1;
        }
        else {
            ++count;
        }

        if (count > res) {
            res = count;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector < int > a(n);
    for (int &item: a) {
        cin >> item;
    }

    sort(a.begin(), a.end());
    cout << countDistinctValues(a) << endl;
    cout << highestFrequency(a) << endl;
    return 0;
}
```

***Python:***

```py
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
```