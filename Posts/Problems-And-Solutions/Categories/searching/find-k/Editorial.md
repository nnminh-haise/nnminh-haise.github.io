
# Tìm k | Editorial - Lời giải

> *Tags: searching*

## Statement - Đề bài

Cho một dãy $A$ có $n \; (1 \le n \le 10^4)$ phần tử là các số nguyên dương $a_1, a_2, a_3, \ldots, a_n \; (1 \le a_i \le 10^4)$ và một số nguyên dương $k \; (1 \le k \le 10^4)$.

***Yêu cầu:*** In ra vị trí nhỏ nhất của $k$ trong dãy $A$. Nếu không tìm thấy $k$ trong $A$, in $-1$.

### Input - Dữ liệu vào

- Dòng đầu tiên là gồm hai số nguyên dương $n$ và $k$ - số lượng phần tử của dãy và số cần tìm.
- Dòng thứ hai là $n$ số nguyên $a_1, a_2, a_3, \ldots, a_n$.

### Output - Dữ liệu ra

- Một số nguyên duy nhất là vị trí của $k$ trong dãy $A$.

---

## Solution - Giải thuật



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

    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == k) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
```

***Python:***

```py
```
