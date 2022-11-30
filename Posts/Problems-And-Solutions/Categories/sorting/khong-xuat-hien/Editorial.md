
# Không xuất hiện | Editorial - Lời giải

> *Tags: Sorting, Distribution*

## Statement - Đề bài

Cho một dãy $A$ gồm $n \; (1 \le n \le 30000)$ số nguyên $a_1, a_2, a_3, \ldots, a_n \; (2 \le a_i \le 10^6)$.

***Yêu cầu:*** Tìm số tự nhiên nhỏ nhất không xuất hiện trong dãy.

### Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $n$.
- Dòng thứ hai là $n$ số nguyên dương của dãy $A$.

### Output - Dữ liệu ra

- Một số nguyên dương $k$ duy nhất thỏa mãn yêu cầu đề bài.

---

## Solution - Giải thuật

Ta có nhận xét sau: số tự nhiên nhỏ nhất không xuất hiện trong dãy sẽ nằm trong đoạn $[0, n]$. Do ñó, ta sử dụng mảng $c[]$ với $c[i]$ là số lần xuất hiện của $x$ trong dãy, nếu $c[x] = 0$ tức là $x$ không xuất hiện trong dãy.

### Optimized solution - Giải thuật tối ưu

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector < int > a(n);
    for (int &item: a) {
        cin >> item;
    }

    int *f = new int [1000001];
    for (int i = 0; i <= 1000000; ++i) {
        f[i] = 0;
    }

    for (int item: a) ++f[item];
    for (int i = 0; i <= 1000000; ++i) {
        if (f[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
```

***Python:***

```py
n = int(input())
a = list(map(int, input().split(' ')))

f = {}

for item in a:
    f[str(item)] = 1

for i in range(0, 1000001):
    if f.get(str(i)) == None:
        print(i)
        break
```
