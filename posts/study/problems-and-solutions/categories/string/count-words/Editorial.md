
# Đếm từ | Editorial - Lời giải

> *Tags: string, basic*

## Statement - Đề bài

Cho một chuỗi $s$ gồm nhiều từ vô nghĩa có độ dài không quá $1000$ kí tự gồm các chữ cái in thường trong bảng chữ cái tiếng anh và dấu cách.

***Yêu cầu:*** đếm số lượng từ có trong chuỗi $s$.

### Input - Dữ liệu vào

- Một chuỗi $s$ duy nhất.

### Output - Dữ liệu ra

- Một số nguyên $p$ là số lượng từ trong chuỗi $s$.

---

## Solution - Giải thuật

Đếm số lượng chuỗi con $p$ khác ` ` trong chuỗi $s$.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int ans = 0;
    int i = 0;
    while (i < s.length()) {
        string tmp = "";
        while (s[i] != ' ') {
            tmp += s[i++];
        }
        ++i;
        if (tmp.length() != 0) {
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}
```

***Python:***

```py
s = input()

ans = 0
index = 0

while index < len(s):
    tmp = ""
    while s[index] != ' ':
        tmp += s[index]
        index += 1
    index += 1
    if len(tmp) > 0:
        ans += 1

print(ans)
```
