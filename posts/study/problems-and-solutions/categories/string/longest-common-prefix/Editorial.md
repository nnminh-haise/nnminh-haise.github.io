
# Tiền tố chung dài nhất | Editorial - Lời giải

> *Tags: string, basic*

## Statement - Đề bài

Cho hai chuỗi $s$ và $p$ có độ dài không quá $1000$ phần tử gồm các kí tự là chữ cái in thường trong bảng chữ cái tiếng anh.

Chuỗi tiền tố là một chuỗi con gồm các kí tự liên tiếp xuất hiện ở đầu chuỗi.

Ví dụ chuỗi tiền tố của chuỗi `abs` là `ab`.

Chuỗi tiền tố chung là chuỗi tiền tố của hai hoặc nhiều dãy.

***Yêu cầu:*** Cho biết độ dài của chuỗi tiền tố chung dài nhất của hai chuỗi $s$ và $p$.

### Input - Dữ liệu vào

- Gồm hai dòng, dòng đầu tiên là chuỗi $s$, dòng thứ hai là chuỗi $p$.

### Output - Dữ liệu ra

- Một số nguyên duy nhất là độ dài của chuỗi tiền tố chung dài nhất.

---

## Solution - Giải thuật

So khớp các kí tự đầu tiên của hai chuỗi.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, p;
    cin >> s >> p;
    int i = 0;
    while (i < min(s.length(), p.length()) & s[i] == p[i]) {
        ++i;
    }

    cout << i<< endl;
    return 0;
}
```

***Python:***

```py
s = input()
p = input()

i = 0

while i < min(len(s), len(p)) and s[i] == p[i]:
    i += 1

print(i)
```
