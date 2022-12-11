
# Bậc thang - VSTEPS | Editorial - Lời giải

> *Tags: Dynamic Programming, Basic*

## Statement - Đề bài

> *Nguồn: [VSTEPS | VNOI](https://oj.vnoi.info/problem/vsteps).*

Bờm chơi trò chơi điện tử Lucky Luke đến màn phải điều khiển Lucky leo lên một cầu thang gồm $n$ bậc.

Các bậc thang được đánh số từ $1$ đến $n$ từ dưới lên trên. Lucky có thể đi lên một bậc thang, hoặc nhảy một bước lên hai bậc thang. Tuy nhiên một số bậc thang đã bị thủng do cũ kỹ và Lucky không thể bước chân lên được. Biết ban đầu, Lucky đứng ở bậc thang số $1$ (bậc thang số $1$ không bao giờ bị thủng).

***Yêu cầu:*** Có bao nhiêu cách để Lucky leo hết được cầu thang? (nghĩa là leo đến bậc thang thứ $n$).

### Input - Dữ liệu vào

- Dòng thứ nhất gồm hai số $n$ và $k$ như mô tả.
- Dòng thứ hai gồm $k$ số cho biết chỉ số của các bậc thang bị hỏng theo thứ tự tăng dần.

### Output - Dữ liệu ra

- In ra phần dư của số cách Lucky leo hết cầu thang khi chia cho $14062008$.

---

## Solution - Giải thuật

- Gọi $dp(i)$ là số cách để đi được đến bậc thang thứ $i$.
- Nếu bạc thang thứ $i$ bị hỏng thì $dp(i) = 0$.
- Ngược lại, $dp(i) = dp(i - 1) + dp(i - 2)$.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    const int MOD = 14062008;

    int n, m;
    cin >> n >> m;
    int* dp = new int [n + 1];
    int* f = new int [n + 1];
    for (int i = 1; i <= n; ++i) {
        f[i] = 1;
        dp[i] = 0;
    }

    for (int i = 1; i <= m; ++i) {
        int temp;
        cin >> temp;
        f[temp] = 0;
    }

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = f[i] * (((dp[i - 1] % MOD) + (dp[i - 2] % MOD)) % MOD);
    }

    cout << dp[n] % MOD << endl;
    return 0;
}
```

***Python:***

```py
n, m = [int(x) for x in input().strip().split(' ')]
arr = []
if m > 0:
    arr = [int(x) for x in input().strip().split(' ')]

f = [1 for _ in range(0, n + 1)]
dp = [0 for _ in range(0, n + 1)]
m = 14062008

for item in arr:
    f[item] = 0

dp[0] = 0
dp[1] = 1
for i in range(2, n + 1):
    dp[i] = f[i] * ((dp[i - 1] % m) + (dp[i - 2] % m)) % m

print(dp[n])

```