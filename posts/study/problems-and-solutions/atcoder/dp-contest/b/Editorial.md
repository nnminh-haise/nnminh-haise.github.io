
# B Frog 2 | DP Contest | Atcoder | Editorial - Lời giải

> *Tags: Dynamic programming, Basic*

## Statement - Đề bài

> *Nguồn: [B | DP Contest | Atcoder](https://atcoder.jp/contests/dp/tasks/dp_b)*

Có $n$ hòn đá được đánh số từ $1$ đến $n$. Với mỗi hòn đá thứ $i$ sẽ có độ cao $h_i$. Có một chú ếch đang ở trên hòn đá $1$. Chú ếch sẽ nhảy từ hòn đá này sang hòn đá khác cho đến khi đến được hòn đá $n$. Mỗi lần, chú ếch có thể nhảy từ hòn đá $i$ sang các hòn đá $i + 1, i + 2, i + 3, \ldots, i + k$. Và chi phí sẽ là chênh lệch chiều cao giữa hai hòn đá mà chú ếch vừa di chuyển.

***Yêu cầu:*** Đưa ra chi phí nhỏ nhất có thể để chú ếch từ hòn đá $1$ di chuyển sang hòn đá $n$.

### Input - Dữ liệu vào

- Dòng đầu tiên là hai số nguyên dương $n \; (2 \le n \le 10^5)$ và $k \; (1 \le k \le 100)$.
- Dòng thứ hai là $n$ số nguyên $h_1, h_2, h_3, \ldots, h_n \; (1 \le h_i \le 10^4)$.

### Output - Dữ liệu ra

- Chi phí nhỏ nhất để chi chuyển từ hòn đá $1$ đến hòn đá $n$.

---

## Solution - Giải thuật

- Gọi $dp(i)$ là chi phí nhỏ nhất để di chuyển từ hòn đá $1$ đến hòn đá $i$.
- Ban đầu, chú ếch ở hòn đá $1$ nên $dp(1) = 0$.
- Từ hòn đá $i$, chú ếch có thể nhảy đến các vị trí $i + 1, i + 2, i + 3, \ldots, i + k$. Do đó, $dp(i + j) = \min(dp(i + j), dp(i) + |h_i - h_{i + j}|)$.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int* a = new int [n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    const int inf = 1e9 + 7;
    int* dp = new int [n];
    for (int i = 0; i < n; ++i) {
        dp[i] = inf;
    }
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i + j < n) {
                dp[i + j] = min(dp[i + j], dp[i] + abs(a[i] - a[i + j]));
            }
        }
    }

    cout << dp[n - 1] << endl;
    return 0;
}
```

***Python:***

```py
n, k = [int(_) for _ in input().strip().split()]
a = [int(_) for _ in input().strip().split()]

dp = [10**9 for _ in range(n)]

dp[0] = 0
for i in range(0, n):
    for j in range(1, k + 1):
        if i + j < n:
            dp[i + j] = min(dp[i + j], dp[i] + abs(a[i] - a[i + j]))

print(dp[n - 1])
```