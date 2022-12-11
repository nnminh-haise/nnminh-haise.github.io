
# Xếp hàng mua vé - NKTICK | Editorial - Lời giải

> *Tags: Dynamic Programming, Basic*

## Statement - Đề bài

> *Nguồn: [NKTICK | VNOI](https://oj.vnoi.info/problem/nktick)*

Có $n$ người sắp hàng mua vé dự buổi hoà nhạc. Ta đánh số họ từ $1$ đến $n$ theo thứ tự đứng trong hàng. Mỗi người cần mua một vé, song người bán vé được phép bán cho mỗi người tối đa hai vé. Vì thế, một số người có thể rời hàng và nhờ người đứng trước mình mua hộ vé. Biết $t_i$ là thời gian cần thiết để người $i$ mua xong vé cho mình. Nếu người $i + 1$ rời khỏi hàng và nhờ người $i$ mua hộ vé thì thời gian để người thứ $i$ mua được vé cho cả hai người là $r_i$.

***Yêu cầu:*** Xác định xem những người nào cần rời khỏi hàng và nhờ người đứng trước mua hộ vé để tổng thời gian phục vụ bán vé là nhỏ nhất.

### Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $n \; (1 \le n \le 60000)$.
- Dòng thứ hai là $n$ số nguyên dương $t_1, t_2, t_3, \ldots, t_n \; (1 \le t_i \le 30000)$.
- Dòng thứ ba là $n - 1$ số nguyên dương $r_1, r_2, r_3, \ldots, r_{n - 1} \; (1 \le r_i \le 30000)$

### Output - Dữ liệu ra

In ra tổng thời gian phục vụ nhỏ nhất.

---

## Solution - Giải thuật

- Gọi $dp(i)$ là thời gian phục vụ nhỏ nhất từ người $1$ đến người $i$ (người thứ $i$ là người mua vé).
- Nếu dãy chỉ có $1$ người thì $dp(1) = t_1$.
- Nếu dãy có $2$ người thì $dp(2) = \min(t_2 + t_1, r_1) = min(t_2 + dp(1), r_1)$.
- Khi dãy có $i$ người thì $dp(i) = \min(t_i + dp(i - 1), r_{i - 1} + dp(i - 2))$.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int* a = new int [n];
    int* b = new int [n - 1];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    long long* dp = new long long [n];
    dp[0] = a[0];
    dp[1] = min(a[1] + a[0], b[0]);
    for (int i = 2; i < n; ++i) {
        dp[i] = min(a[i] + dp[i - 1], b[i - 1] + dp[i - 2]);
    }

    cout << dp[n - 1] << endl;
    return 0;
}
```

***Python:***

```py
n = int(input())
a = [int(x) for x in input().strip().split(' ')]
b = [int(x) for x in input().strip().split(' ')]

dp = [int for _ in range(n)]

dp[0] = a[0]
dp[1] = min(a[0] + a[1], b[0])
for i in range(2, n):
    dp[i] = min(a[i] + dp[i - 1], b[i - 1] + dp[i - 2])

print(dp[n - 1])
```