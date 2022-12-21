
# Tìm khóa | Editorial - Lời giải

> *Tags: string, basic*

## Statement - Đề bài

Cho hai chuỗi $s$ và $p$ có độ dài không quá $1000$ phần tử gồm các kí tự in thường trong bảng chữ cái tiếng anh.

***Yêu cầu:*** Kiểm tra xem chuỗi $p$ có xuất hiện trong chuỗi $s$ hay không. Lưu ý: các ký tự của chuỗi $p$ phải xuất hiện liên tiếp nhau bên trong chuỗi $s$ mới được xác định là chuỗi $p$ ở trong chuỗi $s$.

### Input - Dữ liệu vào

- Gồm hai dòng, dòng đầu tiên là chuỗi $s$, dòng thứ hai là chuỗi $p$.

### Output - Dữ liệu ra

- Nếu chuỗi $p$ xuất hiện trong chuỗi $s$ thì in `yes`, ngược lại in `no`.

---

## Solution - Giải thuật

Gọi $m$ là số lượng phần tử của chuỗi $p$, lần lượt kiểm tra $m$ phần tử liên tiếp trong chuỗi $s$, nếu $m$ phần tử đó giống với chuỗi $p$ thì kết quả bài toán là `yes`. Nếu không tồn tại trường hợp đúng nào, in `no`.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int ans = 0;
    string s, p;
    cin >> s >> p;
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

    cout << (ans == 0 ? "no\n" : "yes\n");
    return 0;
}
```

***Python:***

```py
s = input()
p = input()
ans = 0

for i in range(0, len(s) - len(p) + 1):
    if s[i] == p[0]:
        flag = True
        for j in range(len(p)):
            if s[i + j] != p[j]:
                flag = False
                break
        if flag:
            ans += 1


print("no" if ans == 0 else "yes")
```