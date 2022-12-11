
# C Vacation | DP Contest | Atcoder | Editorial - Lời giải

> *Tags: Dynamic programming, Basic*

## Statement - Đề bài

> *Nguồn: [C | DP Contest | Atcoder](https://atcoder.jp/contests/dp/tasks/dp_c).*

Kì nghỉ hè của Taro sẽ bắt đầu vào ngày mai và anh ấy đã quyết định lên kế hoạch cho nó từ bây giờ.

Kì nghỉ hè sẽ diễn ra $n$ ngày. Và mỗi ngày thứ $i \; (1 \le i \le n)$ của kì nghỉ hè, Taro sẽ chọn một trong các hoạt động sau và làm nó vào ngày hôm ấy.

- `A`: bơi lội và được $a_i$ điểm hạnh phúc.
- `B`: bắt bọ cánh cứng ở sau núi và được $b_i$ điểm hạnh phúc.
- `C`: làm bài tập về nhà và được $c_i$ điểm hạnh phúc.

Taro sẽ trở nên chán một cách nhanh chóng nếu anh ấy làm hai hoạt động giống nhau trong hai hoặc nhiều ngày liên tục.

***Yêu cầu:*** Trong suốt $n$ ngày, hãy tính số điểm hạnh phúc lớn nhất mà Taro có thể nhận được.

### Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $n \; (1 \le n \le 10^5)$.
- $n$ dòng tiếp theo, mỗi dòng gồm ba số nguyên dương $a_i, b_i, c_i \; (1 \le a_i, b_i, c_i \le 10^4)$ lần lượt là số điểm hành phúc của các hoạt động `A, B` và `C` vào ngày thứ $i$.

### Output - Dữ liệu ra

- Một số nguyên duy nhất là tổng số điểm hạnh phúc lớn nhất mà Taro có thể nhận được.

---

## Solution - Giải thuật

- Gọi $dp(i, j)$ là tổng số điểm hạnh phúc lớn nhất nếu Taro làm hoạt động $j \; (1 \le j \le 3)$ vào ngày thứ $i$ (Các hoạt động `A, B, C` sẽ được đánh số là hoạt động $1, 2, 3$).
- Ban đầu, nếu chỉ có $1$ ngày thì sẽ có: $dp(1, 1) = a_1; dp(1, 2) = b_1; dp(1, 3) = c_1$.
- Với ngày thứ $i$, khi hôm nay Taro làm hoạt động $1$ thì chắc chắn ngày hôm trước Taro sẽ làm một trong hai hoạt động $2$ hoặc $3$. Tương tự nếu Taro hôm nay chọn làm hoạt động $2$ hoặc $3$. Do vậy có thể thấy được:

$$
\begin{cases}
dp(i, 1) = \max(dp(i - 1, 2), dp(i - 1, 3)) + a[i]. \\
dp(i, 2) = \max(dp(i - 1, 1), dp(i - 1, 3)) + b[i]. \\
dp(i, 3) = \max(dp(i - 1, 1), dp(i - 1, 2)) + c[i]. \\
\end{cases}
$$

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int [3];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    int** dp = new int* [n];
    for (int i = 0; i < n; ++i) {
        dp[i] = new int [3];
    }

    for (int i = 0; i < 3; ++i) {
        dp[0][i] = a[0][i];
    }

    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + a[i][2];
    }

    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;
    return 0;
}
```

***Python:***

```py
n = int(input())
a = list()
for _ in range(n):
    a.append([int(_) for _ in input().strip().split()])

dp = [[0 for _ in range(3)] for _ in range(n)]
for i in range(3):
    dp[0][i] = a[0][i]

for i in range(1, n):
    dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i][0]
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + a[i][1]
    dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + a[i][2]

print(max(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]))
```