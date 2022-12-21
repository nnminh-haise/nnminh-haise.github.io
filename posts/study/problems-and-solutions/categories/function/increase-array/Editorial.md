
# Dãy tăng | Editorial - Lời giải

> *Tags: Function, Array, Basic*

## Statement - Đề bài

Cho một dãy $A$ có $n \; (1 \le n \le 10000)$ phần tử là các số nguyên dương $a_1, a_2, a_3, \ldots, a_n \; (1 \le a_i \le 10000)$.

Dãy tăng là dãy thỏa mãn tính chất: $a_1 < a_2 < a_3 < \ldots < a_n$.

***Yêu cầu:*** Kiểm tra dãy đã cho có phải là dãy tăng hay không.

### Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $n$.
- Dòng thứ hai gồm $n$ số nguyên dương $a_1, a_2, a_3, \ldots, a_n$.

### Output - Dữ liệu ra

- In ra `true` hoặc `false` tương ứng với việc dãy $A$ đã cho là dãy tăng hoặc không.

---

## Solution - Giải thuật



***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

string check(const int *a, const int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] >= a[i + 1]) {
            return "false";
        }
    }
    return "true";
}

int main() {
    int n;
    cin >> n;
    int *a = new int [n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << check(a, n) << endl;
    return 0;
}
```
