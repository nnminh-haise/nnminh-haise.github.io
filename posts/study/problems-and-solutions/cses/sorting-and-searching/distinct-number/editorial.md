
# Distinct Numbers | Editorial - Lời giải

> *Tags: Sorting, Searching, Set*

## Statement - Đề bài

> *Nguồn: [Distinct Numbers - CSES Problem set](https://cses.fi/problemset/task/1621).*

You are given a list of $n$ integers, and your task is to calculate the number of distinct values in the list.

### Input - Dữ liệu vào

- The first input line has an integer $n \; (1 \le n \le 2 \cdot 10^5)$: the number of values.
- The second line has $n$ integers $x_1, x_2, \ldots,x_n \; (1 \le x_i \le 10^9)$.

### Output - Dữ liệu ra

- Print one integers: the number of distinct values.

---

## Solution - Giải thuật

- Sắp xếp lại dãy theo thứ tự giảm dần (hoặc tăng dần).
- Duyệt qua các phần tử của dãy và đếm các cặp phần tử $a_i \neq a_{i + 1}$.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int* a = new int [n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);

    int ans = 0;
    for (int i = 0; i < n; ++ans) {
        int j = i + 1;
        while (a[i] == a[j]) {
            ++j;
        }
        i = j;
    }
    cout << ans << endl;
    return 0;
}
```

***Python:***

```py
def quick_sort(arr: list, left: int, right: int):
    i = left
    j = right
    pivot = arr[(right - left) // 2 + left]

    while i <= j:
        while arr[i] < pivot:
            i += 1

        while arr[j] > pivot:
            j -= 1

        if i <= j:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1

    if left < j:
        quick_sort(arr, left, j)
    if i < right:
        quick_sort(arr, i, right)

    return arr


def sorting_solution(a: list[int]):
    a = quick_sort(a, 0, len(a) - 1)
    ans = 1
    for i in range(len(a) - 1):
        if a[i] != a[i + 1]:
            ans += 1

    return ans


n = int(input())
a = list(map(int, input().split(' ')))

print(sorting_solution(a))
```

