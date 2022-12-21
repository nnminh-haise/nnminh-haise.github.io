
# Đếm chuỗi con | Editorial - Lời giải

> *Tags: string, basic*

## Statement - Đề bài

Cho một chuỗi $s$ và $p$ lần lượt có độ dài $n \; (1 \le n \le 1000)$ và $m \; (1 \le m \le 1000)$ gồm các kí tự in thường trong bản chữ cái tiếng anh. 

***Yêu cầu:*** Đếm số lần xuất hiện của chuỗi $p$ trong chuỗi $s$. Lưu ý: các kí tự của chuỗi $p$ phải xuất hiện liên tiếp trong chuỗi $s$ mới tính là một lần xuất hiện.

### Input - Dữ liệu vào

- Gồm hai dòng, dòng thứ nhất là chuỗi $s$, dòng thứ hai là chuỗi $p$.

### Output - Dữ liệu ra

- Một số nguyên duy nhất là số lần xuất hiện của chuỗi $p$ trong $s$.

---

## Solution - Giải thuật

Gọi $i$ là chỉ số của chuỗi $s$ với $i \in [0, |s| - 1]$. Với mỗi $i \in [0, |s| - |p| + 1]$, với mỗi $j \in [0, |p|]$, nếu không tồn tại $s[i + j] \neq p[j]$ thì có nghĩa rằng có một chuỗi $p$ đã xuất hiện trong $s$. Lặp lại quá trình này cho đến hết dãy.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, p;
    cin >> s >> p;
    int ans = 0;
    for (int i = 0; i < s.length() - p.length() + 1; ++i) {
        if (s[i] == p[0]) {
            bool flag = true;
            for (int j = 0; j < p.length(); ++j) {
                if (s[i + j] != p[j]) {
                    flag = false;
                }
            }
            ans += flag;
        }
    }

    cout << ans << endl;
    return 0;
}
```

***Python:***

```py
s = input()
p = input()
ans = 0

for i in range(0, len(s) - len(p) + 1):
    flag = True
    for j in range(0, len(p)):
        if s[i + j] != p[j]:
            flag = False
    if flag:
        ans += 1

print(ans)
```
