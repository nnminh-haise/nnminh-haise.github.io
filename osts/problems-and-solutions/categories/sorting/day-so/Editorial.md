
# Dãy số | Editorial - Lời giải

> *Tags: Sorting, Distribution*

### Statement - Đề bài

Cho dãy số $F$ gồm $n \; (2 < n \le 10^6)$ số nguyên $F = (f_1, f_2, f_3, \ldots, f_n)$ được định nghĩa như sau: 

$$
f_i =
\begin{cases}
1, \; \text{if} \; 1 \le i \le 2 \\
(f_{i - 1} + f_{i - 2}) \mod 128, \; \text{if} \; 2 < i \le n
\end{cases}
$$

***Yêu cầu:*** Khi sắp xếp dãy $F$ theo thứ tự không giảm thì số thứ $k \; (k \le n)$ có giá trị là bao nhiêu?

### Input - Dữ liệu vào

- Một dòng duy nhất gồm hai số $n$ và $k$ như mô tả.

### Output - Dữ liệu ra

- Một số nguyên duy nhất là giá trị $f_k$ cần tìm.

---

## Solution - Giải thuật

Dễ thấy rằng giá trị của các phần tử trong dãy $F$ sẽ nằm trong đoạn $[0, 127]$. Do đó ta có thể sử dụng một thuật toán đếm phân phối như sau:

- Xây dựng hàm $g()$ với $g(i)$ là số lần xuất hiện của giá trị $i$ trong dãy $F$.
- Giá trị thứ $k$ của dãy $F$ sau khi sắp xếp là giá trị $P$ nhỏ nhất thỏa mãn: $$g(0) + g(1) + g(2) + \ldots + g(P) \ge k$$



***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector < int > g(128, 0);
    int f_0 = 1, f_1 = 1, f_2 = 0;
    g[1] = 2;

    for (int i = 3; i <= n; ++i) {
        f_2 = (f_0 + f_1) % 128;
        ++g[f_2];
        f_0 = f_1;
        f_1 = f_2;
    }

    int count = 0;
    int p = 0;
    for (int i = 0; i < 128; ++i) {
        count += g[i];
        if (count >= k) {
            p = i;
            break;
        }
    }
    cout << p << endl;
    return 0;
}
```

***Python:***

```py
n, k = list(map(int, input().split(' ')))

f = [0 for i in range(0, n + 1)]
g = [0 for i in range(0, 128)]
f[1] = f[2] = 1
g[1] = 2

for i in range(3, n + 1):
    f[i] = (f[i - 1] + f[i - 2]) % 128
    g[f[i]] += 1

count = 0
p = 0
for i in range(0, 128):
    count += g[i]
    if (count >= k):
        p = i
        break

print(p)
```