
# Đảo ngược chuỗi | Editorial - Lời giải

> *Tags: string, basic*

## Statement - Đề bài

Cho một chuỗi $s$ có độ dài $n \; (1 \le n \le 1000)$ gồm các kí tự in thường trong bảng chữ cái tiếng anh.

***Yêu cầu:*** In ra chuỗi đảo ngược của chuỗi đã cho.

### Input - Dữ liệu vào

- Một dòng duy nhất là chuỗi $s$.

### Output - Dữ liệu ra

- Một dòng duy nhất là chuỗi $s$ sau khi bị đảo ngược.

---

## Solution - Giải thuật

> *Có thể sử dụng các hàm hoặc toán tử có sẵn mà ngôn ngữ lập trình cho sẵn. Nhưng không hoan nghênh!*

Chuỗi đảo ngược là chuỗi ban đầu nhưng được thể hiện theo thứ tự ngược lại. Do đó, có thể sử dụng một vòng lặp và in ngược thứ tự của chuỗi đã cho.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    string res = "";
    for (int i = s.length() - 1; i >= 0; --i) {
        res += s[i];
    }

    cout << res << endl;
    return 0;
}
```

***Python:***

```py
s = input()
res = ""

for i in range(len(s) - 1, -1, -1):
    res += s[i]

print(res)
```
