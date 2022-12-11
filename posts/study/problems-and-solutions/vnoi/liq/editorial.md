
# Dãy con tăng đơn điệu dài nhất - LIQ | Editorial - Lời giải

> *Tags: Dynamic programming, basic*

## Statement - Đề bài

> *Nguồn: [LIQ | VNOI](https://oj.vnoi.info/problem/liq).*

Cho một dãy số nguyên $A$ gồm $n \; (1 \le n \le 1000)$ phần tử $a_1, a_2, a_3, \ldots, a_n \; (1 \le a_i \le 10000)$.

Biết dãy con tăng đơn điệu là $1$ dãy $a_{i_1}, a_{i_2}, a_{i_3}, \ldots, a_{i_k}$ thỏa mãn $i_1 < i_2 < i_3 < \ldots < i_k$ và $a_{i_1} < a_{i_2} < a_{i_3} < \ldots < a_{i_k}$.

***Yêu cầu:*** Cho biết dãy con tăng đơn điệu dài nhất của dãy $A$ đã cho có bao nhiêu phần tử.

### Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $n$ - số lượng phần tử của dãy $A$.
- Dòng thứ hai gồm $n$ số nguyên $a_1, a_2, a_3, \ldots, a_n$.

### Output - Dữ liệu ra

- Độ dài của dãy con tăng đơn điệu dài nhất.

---

## Solution - Giải thuật

- Gọi $dp(i)$ là **độ dài của dãy con tăng đơn điệu dài nhất nhận $a_i$ là phần tử cuối cùng** của dãy.
- Nhận xét: "**Dãy có $1$ phần tử luôn là dãy tăng đơn điệu**". Do vậy, nếu mọi phần tử của dãy $A$ là một dãy có độ dài $1$ thì sẽ có được $dp(i) = 1 \forall i \in [1, n]$.
- Khi xét tới phần tử $i$ của dãy $A$, đặt $dp(j) = m \; (j < i)$, khi đó, nếu $a_j < a_i$ thì có thể nhận $a_i$ là phần tử cuối cùng của dãy con tăng đơn điệu dài nhất có độ dài $m + 1$. Nếu $dp(i) < m + 1$ thì cập nhật $dp(i) = m + 1$.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *a = new int [n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int *dp = new int [n];
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
    }

    int ans = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
    delete[] a;
    delete[] dp;
    return 0;
}
```

***Python:***

```py
n = int(input())
a = list(map(int, input().split(' ')))

dp = [1 for _ in range(n)]

ans = 1

for i in range(1, n):
    for j in range(0, i):
        if a[j] < a[i]:
            dp[i] = max(dp[i], dp[j] + 1)
    
    ans = max(ans, dp[i])

print(ans)
```