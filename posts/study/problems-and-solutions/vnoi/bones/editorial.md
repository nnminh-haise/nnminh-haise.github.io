
# Xúc xắc bò - Bones | Editorial - Lời giải

> *Tags: Dynamic Programming, Basic*

## Statement - Đề bài

> *Nguồn: [Bones | VNOI](https://oj.vnoi.info/problem/bones).*

Bessie rất yêu thích chơi những trò chơi đổ xúc xắc và cô bò này đã nài được bác nông dân John chở tới cửa hàng đồ chơi và cô bò đã mua  cái xúc xắc về để lăn.

Những viên xúc xắc này tương ứng có $S_1, S_2$ và $S_3$ mặt đều nhau, các mặt được đánh số từ $1 \rightarrow S_1, 1 \rightarrow S_2$ và $1 \rightarrow S_3 \; (2 \le S_1 \le 20, 2 \le S_2 \le 20, 2 \le S_3 \le 40)$.

Bessie cứ thả xúc xắc liên tục và mỗi lần lại ghi nhận lại  số nguyên là tổng giá trị của  mặt xúc xắc thả được. Mục đích của cô bò là để tìm ra xem tổng giá trị nào xuất hiện nhiều nhất.

***Yêu cầu:*** Cho số mặt của $3$ xúc xắc, hãy xác định xem tổng giá trị nào xuất hiện nhiều nhất. Nếu có nhiều hơn $1$ giá trị xuất hiện nhiều nhất thì ghi ra giá trị nhỏ nhất.

### Input - Dữ liệu vào

- Một dòng duy nhất gồm $3$ số nguyên dương $S_1, S_2, S_3$.

### Output - Dữ liệu ra

- Một số nguyên nhỏ nhất là tổng giá trị xuất hiện nhiều lần nhất, giả sử rằng xác suất các mặt xúc xắc xuất hiện là như nhau.

---

## Solution - Giải thuật

- Gọi $dp(i)$ là số lần xuất hiện của giá trị tổng $i$.
- Từ giả thuyết đề bài, có thể nhìn ra được $i \in [3, S_1 + S_2 + S_3]$.
- Vì giới hạn $S_1, S_2, S_3$ khá nhỏ nên có thể thử từng tổng có thể và cập nhật vào $dp()$.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int* dp = new int [2000];
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            for (int k = 1; k <= c; ++k) {
                ++dp[i + j + k];
            }
        }
    }

    int ans = 0;
    dp[0] = -1;

    for (int i = 3; i <= a + b + c; ++i) {
        if (dp[ans] < dp[i]) {
            ans = i;
        }
    }

    cout << ans << endl;
    return 0;
}
```

***Python:***

```py
s1, s2, s3 = list(map(int, input().split(' ')))
dp = [0 for _ in range(2000)]

for i in range(1, s1 + 1):
    for j in range(1, s2 + 1):
        for k in range(1, s3 + 1):
            dp[i + j + k] += 1

ans = 0
dp[0] = -1

for i in range(3, s1 + s2 + s3 + 1):
    if dp[ans] < dp[i]:
        ans = i

print(ans)
```