
# Cận dưới | Editorial - Lời giải

> *Tags: Searching, Binary Search, Sorting*

## Statement - Đề bài

Cho dãy $A$ có $n \; (1 \le n \le 10000)$ phần tử $a_1, a_2, a_3, \ldots, a_n \; (1 \le a_i \le 10000)$ là các số nguyên dương và một số nguyên dương $k \; (1 \le k \le 10000)$. Dãy $A$ được đánh chỉ số từ $0$.

Cận dưới của một số $k$ bất kì trong dãy $A$ là vị trí nhỏ nhất của $k$ trong dãy $A$ đã sắp xếp hoặc vị trí lớn nhất của số nguyên lớn nhất nhỏ hơn $k$.

***Yêu cầu:*** Tìm cận dưới của $k$ trong dãy $A$.

### Input - Dữ liệu vào

- Dòng đầu tiên gồm hai số nguyên dương $n$ và $k$.
- Dòng thứ hai gồm $n$ số nguyên dương $a_1, a_2, a_3, \ldots, a_n$.

### Output - Dữ liệu ra

- Một số nguyên duy nhất là chỉ số của cận dưới của $k$ trong dãy $A$.

---

## Solution - Giải thuật

Đây là một cải tiến của thuật tìm kiếm nhị phân cơ bản.

Sau khi sắp xếp dãy theo chiều tăng dần. Gọi $l$ và $r$ là chỉ số đầu và chỉ số cuối của dãy. Khởi tạo $p = +\infty$ là chỉ số của cận dưới.

- Chừng nào $l \le r$ thì lặp lại các bước sau:

    - $mid = (r - l + 1) \div 2 + l$
    - Nếu $k \le a[mid]$ thì cập nhật $p = \min(p, mid)$ và $r = mid - 1$.
    - Ngược lại, $l = mid + 1$.

- Khi vòng lặp kết thúc, giá trị của $p$ là chỉ số của cận dưới của $k$ trong dãy $A$.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int lowerBound(vector < int > &a, int k) {
    int p = 1e9 + 7;
    int left = 0, right = a.size() - 1;
    while (left <= right) {
        int mid = (right - left + 1) / 2 + left;
        if (k <= a[mid]) {
            p = min(p, mid);
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return p;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector < int > a(n);
    for (int &item: a) {
        cin >> item;
    }

    cout << lowerBound(a, k) << endl;
    return 0;
}
```

***Python:***

```py
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
```