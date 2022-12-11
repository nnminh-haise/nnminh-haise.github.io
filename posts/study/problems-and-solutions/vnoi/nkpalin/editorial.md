
# Chuỗi đối xứng - NKPALIN | Editorial - Lời giải

> *Tags: Dynamic Programming, Basic*

## Statement - Đề bài

> *Nguồn: [NKPALIN | VNOI](https://oj.vnoi.info/problem/nkpalin).*

Một chuỗi được gọi là đối xứng (palindrome) nếu như khi đọc chuỗi này từ phải sang trái cũng thu được chuỗi ban đầu.

***Yêu cầu:*** tìm một chuỗi con đối xứng dài nhất của một chuỗi $s$ cho trước. Chuỗi con là chuỗi thu được khi xóa đi một số ký tự từ chuỗi ban đầu.

### Input - Dữ liệu vào

- Một dòng duy nhất chứa chuỗi $s$ có độ dài không quá $2000$ kí tự.

### Output - Dữ liệu ra

- Một dòng duy nhất là chuỗi con đối xứng dài nhất.

---

## Solution - Giải thuật

- Gọi $p$ là chuỗi đảo ngược của $s$. Khi đó, bài toán trở thành tìm chuỗi con chung dài nhất của hai chuỗi $s$ và $p$.
- Gọi $dp(i, j)$ là độ dài chuỗi con chung dài nhất khi chuỗi $s$ có $i$ kí tự đầu tiên và chuỗi $p$ có $j$ kí tự đầu tiên.
- Nếu $s_i = p_j$ thì $dp(i, j) = dp(i - 1, j - 1) + 1$.
- Ngược lại, $dp(i, j) = \max(dp(i - 1, j), dp(i, j - 1))$.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, p;
    cin >> s;
    p = s;
    reverse(p.begin(), p.end());

    int** dp = new int* [(int)s.length() + 1];
    for (int i = 0; i <= (int)s.length(); ++i) {
        dp[i] = new int [(int)s.length() + 1];
    }

    dp[0][0] = 0;
    for (int i = 1; i <= (int)s.length(); ++i) {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for (int i = 1; i <= (int)s.length(); ++i) {
        for (int j = 1; j <= (int)s.length(); ++j) {
            if (s[i - 1] == p[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = s.length(), j = s.length();
    string ans = "";
    while (i >= 1 && j >= 1) {
        if (s[i - 1] == p[j - 1]) {
            ans = s[i - 1] + ans;
            --i;
            --j;
        }
        else {
            if (dp[i - 1][j] == dp[i][j]) {
                --i;
            }
            else if (dp[i][j - 1] == dp[i][j]) {
                --j;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
```

***Python:***

```py
s = input()
p = s[::-1]

dp = [[0 for _ in range(len(s) + 1)] for _ in range(len(s) + 1)]

for i in range(1, len(s) + 1):
    for j in range(1, len(s) + 1):
        if s[i - 1] == p[j - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

ans = ""
i = j = len(s)
while i >= 1 and j >= 1:
    if s[i - 1] == p[j - 1]:
        ans = s[i - 1] + ans
        i -= 1
        j -= 1
    else:
        if dp[i - 1][j] == dp[i][j]:
            i -= 1
        else:
            j -= 1

print(ans)
```