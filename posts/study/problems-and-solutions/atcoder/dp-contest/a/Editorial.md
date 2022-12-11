
# A Frog 1 | DP Contest | Atcoder | Editorial - Lời giải

> *Tags: Dynamic programming, Basic*

## Statement - Đề bài

> *Nguồn: [A | DP Contest | Atcoder](https://atcoder.jp/contests/dp/tasks/dp_a)*

Có $n$ hòn đá được đánh số từ $1$ đến $n$. Với mỗi hòn đá thứ $i$ sẽ có độ cao $h_i$. Có một chú ếch đang ở trên hòn đá $1$. Chú ếch sẽ nhảy từ hòn đá này sang hòn đá khác cho đến khi đến được hòn đá $n$. Mỗi lần, chú ếch có thể nhảy từ hòn đá $i$ sang hòn đá $i + 1$ hoặc hòn đá $i + 2$. Và chi phí sẽ là chênh lệch chiều cao giữa hai hòn đá mà chú ếch vừa di chuyển.

***Yêu cầu:*** Đưa ra chi phí nhỏ nhất có thể để chú ếch từ hòn đá $1$ di chuyển sang hòn đá $n$.

### Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $n \; (2 \le n \le 10^5)$ - là số lượng hòn đá.
- Dòng thứ hai là $n$ số nguyên $h_1, h_2, h_3, \ldots, h_n \; (1 \le h_i \le 10^4)$.

### Output - Dữ liệu ra

- Chi phí nhỏ nhất để chi chuyển từ hòn đá $1$ đến hòn đá $n$.

---

## Solution - Giải thuật

- Gọi $dp(i)$ là chi phí nhỏ nhất để di chuyển từ hòn đá $1$ đến hòn đá $i$.
- Ban đầu, chú ếch ở hòn đá $1$ nên $dp(1) = 0$.
- Xét hòn đá $2$, vì chú ếch ban đầu ở hòn đá $1$ nên chỉ có duy nhất $1$ cách từ hòn đá $1$ nhảy sang hòn đá $2$. Do đó $dp(2) = |h_1 - h_2|$.
- Xét hòn đá $i \; (2 < i)$, để đến được hòn đá $i$ thì chú ếch có thể nhảy từ hòn đá $i - 1$ hoặc hòn đá $i - 2$. Do đó: $dp(i) = \min(dp(i - 1) + |h_i - h_{i - 1}|, dp(i - 2) + |h_i - h_{i - 2}|)$.

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

    int* f = new int [n];
    f[0] = 0;
    f[1] = abs(a[0] - a[1]);
    for (int i = 2; i < n; ++i) {
        f[i] = min(f[i - 1] + abs(a[i - 1] - a[i]), f[i - 2] + abs(a[i - 2] - a[i]));
    }
    cout << f[n - 1] << endl;
    return 0;
}
```

***Python:***

```py
n = int(input())
a = [int(x) for x in input().strip().split()]
f = [0 for i in range(n)]

f[0] = 0;
f[1] = abs(a[1] - a[0]);
for i in range(2, n):
    f[i] = min(f[i - 1] + abs(a[i - 1] - a[i]), f[i - 2] + abs(a[i - 2] - a[i]))

print(f[n - 1])
```